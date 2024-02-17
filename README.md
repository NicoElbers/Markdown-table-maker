# Markdown table maker c
I'm creating a Markdown table maker in c. The tables are based on [GitHub flavored Markdown](https://github.github.com/gfm/#tables-extension-).
## Features
### Current
So far included features are:
- Creating headers and data points from user input
    - This is all done sequentially, for now previous data points/ headers cannot be revisited
- Seeing a live update of the table as you're creating
    - This is the Markdown that would be your output
    - For now you have to copy this to actually use the table.
### Planned
Planned features are:
- Auto alignment
    - I want to make sure that a column is always as wide as its largest element and that every column is aligned
- Editing tables
    - I want to let users edit their table afterward, like editing data points, adding/ removing columns, adding/ removing rows etc.
- TUI interface
    - I want to create a TUI interface for users
    - This entails that instead of simply printing more things to the terminal text is overriden to create a better looking experience.
    - This will be done using ANSI escape codes
