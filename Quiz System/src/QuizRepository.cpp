#include "QuizRepository.h"
#include "json.hpp"
#include <fstream>
#include <sstream>

using json = nlohmann::json;

QuizRepository::QuizRepository(const std::string& path) : filePath(path) {}

bool QuizRepository::fileExists() const {
    std::ifstream in(filePath.c_str());
    return static_cast<bool>(in);
}

std::vector<Question> QuizRepository::loadQuestions() const {
    std::vector<Question> questions;
    std::ifstream in(filePath.c_str());
    if (!in)
        return questions;

    std::stringstream buffer;
    buffer << in.rdbuf();
    std::string raw = buffer.str();
    if (raw.empty())
        return questions;

    try {
        json data = json::parse(raw);
        if (!data.contains("questions") || !data["questions"].is_array())
            return questions;

        for (size_t i = 0; i < data["questions"].size(); ++i) {
            const json& item = data["questions"][i];
            if (!item.contains("id") || !item.contains("text") ||
                !item.contains("options") || !item.contains("correctIndex"))
                continue;
            if (!item["options"].is_array())
                continue;

            std::vector<std::string> options;
            for (size_t j = 0; j < item["options"].size(); ++j)
                options.push_back(item["options"][j].get<std::string>());

            int correctIndex = item["correctIndex"].get<int>();
            if (options.empty() || correctIndex < 0 || correctIndex >= static_cast<int>(options.size()))
                continue;

            questions.push_back(Question(item["id"].get<int>(),
                                         item["text"].get<std::string>(),
                                         options,
                                         correctIndex));
        }
    } catch (...) {
        questions.clear();
    }

    return questions;
}
