# Changelog

## 0.2
* `-y` flag implemented
* fixed silly bugs (no method for supplementary days)
* simplified date parser
* added other silly little bugs (leap years are shifted one place, first of the month isn't highlighted)
* created CHANGELOG.md

## 0.3
* `-w` flag implemented
* fixed bug where roman numeral was one year more
* fixed bug where month year wasn't highlighted when showing current date
* string on supplementary days now shows year
* found new bug !! (5th and 6th supplementary days overflow)

## 0.4
* found new bug where `-y` with specific only `[year]` gets the previous year (maybe related to supp. days thing).
* Added [Makefile](Makefile).
* Started adaptation for multilanguage.

## 0.4.1
* Fixed year when using current date (previously displayed one year less).
* Provided date now has its own way of filling [`date_t`](src/fcal.h#L18), instead of being converted to seconds since epoch (therefore supporting dates before 1 vendémiaire 228)
* Tested on Windows after adding [`tmoff.c`](src/tmoff.c)
* Realised localisation in Windows is messed up. Looking into it.

## 0.4.2
* Added a first iteration of long options of arguments (trying to find a more elegant solution than strcmp result).
