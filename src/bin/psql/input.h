/*
 * psql - the PostgreSQL interactive terminal
 *
 * Copyright (c) 2000-2005, PostgreSQL Global Development Group
 *
 * $PostgreSQL: pgsql/src/bin/psql/input.h,v 1.24 2006/02/11 21:55:35 momjian Exp $
 */
#ifndef INPUT_H
#define INPUT_H

/*
 * If some other file needs to have access to readline/history, include this
 * file and save yourself all this work.
 *
 * USE_READLINE is the definite pointers regarding existence or not.
 */
#ifdef HAVE_LIBREADLINE
#define USE_READLINE 1
#if defined(HAVE_READLINE_READLINE_H)
#include <readline/readline.h>
#elif defined(HAVE_EDITLINE_READLINE_H)
#include <editline/readline.h>
#elif defined(HAVE_READLINE_H)
#include <readline.h>
#endif
#if defined(HAVE_READLINE_HISTORY_H)
#include <readline/history.h>
#elif defined(HAVE_EDITLINE_HISTORY_H)
#include <editline/history.h>
#elif defined(HAVE_HISTORY_H)
#include <history.h>
#endif
#endif


char	   *gets_interactive(const char *prompt);
char	   *gets_fromFile(FILE *source);

void		initializeInput(int flags);
bool		saveHistory(char *fname);

void pgadd_history(char *s, PQExpBuffer history_buf);
void pgclear_history(PQExpBuffer history_buf);
void pgflush_history(PQExpBuffer history_buf);


#endif   /* INPUT_H */
