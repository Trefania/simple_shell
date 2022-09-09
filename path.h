#ifndef PATH_H
#define PATH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <info.h>
#include <list.h>
#include <types.h>

char *search_path(info_t *info, list_t *path);

#endif /* PATH_H */
