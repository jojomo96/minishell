/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_wildcard.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:07:49 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/21 21:27:40 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int match_pattern(const char *filename, const char *pattern) {
    const char *f = filename;
    const char *p = pattern;

    while (*f && *p) {
        if (*p == '*') {
            p++;
            if (!*p) {
                return 1; // Pattern ends with '*', so it matches the rest of the filename
            }
            while (*f) {
                if (match_pattern(f, p)) {
                    return 1;
                }
                f++;
            }
            return 0;
        } else if (*p == '"') {
            p++;
            while (*p && *p != '"') {
                if (*p != *f) {
                    return 0;
                }
                p++;
                f++;
            }
            if (*p == '"') {
                p++;
            }
        } else if (*p == '?') {
            if (!*f) {
                return 0;
            }
            p++;
            f++;
        } else {
            if (*p != *f) {
                return 0;
            }
            p++;
            f++;
        }
    }

    // Handle trailing '*'
    if (*p == '*') {
        p++;
    }

    return !*f && !*p;
}

void expand_wildcard(const char *pattern) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            if (match_pattern(entry->d_name, pattern)) {
                printf("%s ", entry->d_name);
            }
        }
    }
    closedir(dir);
    printf("\n");
}
