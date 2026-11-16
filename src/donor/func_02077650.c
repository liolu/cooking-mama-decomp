/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02065438 from projets/children-of-mana/src/auto/func_02065438.c (same code in another game of this workspace), reused
 * by tools/donor_match.py */
typedef struct {
    unsigned short first, last;
    int pad04;
    int mode;
    int *recs;
} Seg;
typedef struct {
    int *cur;
    int dir;
    int active;
    int fc;
    int len;
    int mode;
    Seg *seg;
    volatile int callback_enabled;
    int callback_arg;
    void (*callback)(int, int);
    unsigned short callback_frame;
} Obj;
extern void func_02077834(Obj *o);
extern int func_020152f8(int x);
static inline int needs_step(Obj *o) {
    if (o->active && o->fc >= ((unsigned short *) o->cur)[2] << 12) {
        return 1;
    }
    return 0;
}
static inline int at_end(Obj *o) {
    int *cur = o->cur;
    if ((o->len > 0) ^ o->dir) {
        return cur >= (int *) ((char *) o->seg->recs + (o->seg->first << 3));
    }
    return cur <= (int *) ((char *) o->seg->recs + (o->seg->last << 3) - 8);
}
static inline unsigned int frame_index(Obj *o) {
    return ((unsigned int) ((char *) o->cur - (char *) o->seg->recs) << 13) >> 16;
}
static inline void run_callback(Obj *o) {
    int mode           = o->callback_enabled;
    unsigned int frame = frame_index(o);
    switch (mode) {
        case 2:
            if (frame == o->callback_frame) {
                o->callback(o->callback_arg, frame);
            }
            break;
        case 3:
            o->callback(o->callback_arg, frame);
            break;
    }
}
int func_02077650(Obj *o, int step) {
    int changed = 0;
    if (o->active != 1) {
        return 0;
    }
    o->fc += func_020152f8((int) (((long long) o->len * step + 0x800) >> 12));
    while (needs_step(o)) {
        int end;
        changed = 1;
        o->fc -= ((unsigned short *) o->cur)[2] << 12;
        if ((o->len > 0) ^ o->dir) {
            o->cur += 2;
        } else {
            o->cur -= 2;
        }
        end = at_end(o);
        if (end) {
            func_02077834(o);
        }
        if (o->callback_enabled) {
            run_callback(o);
        }
    }
    return changed;
}
