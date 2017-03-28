# lvc

Ugly program to "calculate" the week in the academic year for some swedish universities.

Also includes lvc-lite, which doesn't have custom date functionality or help text, but runs faster.

## Dependencies

- lvc
    - coreutils

- lvc-lite
    - no idea

## Installation

1. Clone this repository.
    - for **lvc**
        1. `make`
        2. Copy `lvc` to somewhere in your PATH.
    - for **lvc-lite**
        1. `make lite`
        2. Copy `lvc-lite` to somewhere in your PATH.

## Usage

### lvc

	lvc [OPTION]

      -date DATE    Get the week for DATE. Default is today.
                    Works like date's -d flag.
      -h            Display this help message.

### lvc-lite

    lvc-lite

lvc-lite has no options. It just gets the week for today's date.

## Output

- LVn for teaching weeks
- TV for examination weeks
- OTV for reexamination weeks
- Vn for other weeks

Where n is the number of the week.
