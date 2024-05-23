#define K * 1024
#define M K K
#define G M M

#define BUFFER_MAX 1 G
#define BUFFER_MIN 1 K
#define CURSOR_EDGE 4
#define CURSOR_MAX 1
#define EDITOR_EXIT 1

typedef struct {
    size_t x;
    size_t y;
    bool active;
} Cursor;

typedef struct {
    Cursor *cursors;
    size_t lines;
    size_t buffer_size;
    size_t buffer_usage;
    size_t buffer_index;
    char *buffer;
    const char * file_name;
    bool file_exists;
    int mode;
} Editor;

Editor * init_editor(const char*);
void render_editor(const Editor *);
int interact(Editor*, char);
