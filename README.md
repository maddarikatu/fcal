# FCAL

French Republican Calendar on the terminal.

## Installation

Installation tested on GNU/Linux and Windows using MSYS2

```bash
make
./fcal -[hsSvy] [[[day] month] year]
```

### Options
* `-h` prints help message,
* `-s` prints date string (after calendar)
* `-S` prints date string (only)
* `-v` prints version
* `-y` prints whole year

* `[day]` specific day (needs `[month]` and `[year]`)
* `[month]` specific month (month number 1-13, month name or abbreviation; needs `[year]`)
* `[year]` specific year (228-...; currently not supporting dates before 01-01-2028 or gregorian sept. 22, 2020)

**NOTES**

* In the case of `-Ss` or `-sS` the second option overrides the first.
* Printing the string works best when no other argument is provided.
* All printed text is only in french (not a bug) (working on multilanguage)
* Localisation is not made for Windows (accented words look fancy)
