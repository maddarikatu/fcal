# FCAL

French Republican Calendar on the terminal.

## Installation

Installation tested on GNU/Linux and Windows using MSYS2

```bash
make
./fcal [opts] [[[day] month] year]
```

### Options
* `-h`, `--help` prints help message,
* `-s`, `--string` prints date string (after calendar)
* `-S`, `--onlystring` prints date string (only)
* `-v`, `--version` prints version
* `-y`, `--year` prints whole year

* `[day]` specific day (needs `[month]` and `[year]`)
* `[month]` specific month (month number 1-13, month name or abbreviation; needs `[year]`)
* `[year]` specific year

**NOTES**

* In the case of `-Ss` or `-sS` the second option overrides the first.
* Printing the string works best when no other argument is provided.
* All printed text is only in french (not a bug) (working on multilanguage)
* Localisation is not made for Windows (accented words look fancy)
* Long options do not work on Windows.
