# Intentional Defects

This Contact Manager project has been intentionally modified to contain obvious defects for testing practice.

1. `Contact::getPhone()` returns the contact name instead of the stored phone number.
2. `Contact::setName()` writes the new name into the phone field instead of the name field.
3. `Utils::isValidName()` accepts whitespace-only names because it only checks whether the string is non-empty.
4. `Utils::isValidPhone()` validates only the first character, so values like `1abc` are accepted as phone numbers.
5. `Utils::contains()` is now case-sensitive and only matches prefixes, so searches no longer find partial or differently cased names.
6. `ContactRepository::load()` starts reading saved contacts at index `1`, so the first saved contact is skipped.
7. `ContactRepository::save()` adds `1000` to every saved contact ID, corrupting persisted IDs.
8. `ContactRepository::remove()` deletes the first contact even when a different matching ID was found.
9. `ContactRepository::update()` updates the first contact whose ID does not match the requested ID.
10. `ContactService::generateId()` returns the current maximum ID instead of `maxId + 1`, creating duplicate IDs.
