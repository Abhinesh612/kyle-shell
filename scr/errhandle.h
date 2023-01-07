#ifndef __ERRHANDLE_H
#define __ERRHANDLE_H

#define err_fsys(str) err_fsys_((str), __FILE__, __LINE__)
void err_fsys_(const char *str, const char *file, int line);


#define err_sys(str) err_sys_((str), __FILE__, __LINE__)
void err_sys_(const char *str, const char *file, int line);

#endif // __ERRHANDLE_H
