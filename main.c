#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ncurses.h>
#include <unistd.h>

#include "editor.h"

int main(int argc, char **argv) {

    if(argc > 2) {
        fputs("Please specify only one file as of now", stderr);
        return 1;
    }

    initscr();
    Editor *editor;
    editor = init_editor(argv[1]);

    for(;;) {
        refresh();
        clear();
        render_editor(editor);
        if(interact(editor, getch()) == EDITOR_EXIT) {
            free(editor->buffer);
            free(editor);
            break;
        }
    }

    endwin();
    return 0;
}
