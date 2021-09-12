/*
 * Supporting routines used in common by all the various components of
 * the SSH system.
 */

#include <assert.h>
#include <stdlib.h>

#include "putty.h"
#include "ssh.h"
#include "sshchan.h"

/* ----------------------------------------------------------------------
 * Centralised standard methods for other channel implementations to
 * borrow.
 */

void chan_remotely_opened_confirmation(__attribute__((unused)) Channel *chan)
{
    unreachable("this channel type should never receive OPEN_CONFIRMATION");
}

void chan_remotely_opened_failure(__attribute__((unused)) Channel *chan,
                                  __attribute__((unused)) const char *errtext)
{
    unreachable("this channel type should never receive OPEN_FAILURE");
}

bool chan_default_want_close(__attribute__((unused)) Channel *chan,
                             bool sent_local_eof,
                             bool rcvd_remote_eof)
{
    /*
     * Default close policy: we start initiating the CHANNEL_CLOSE
     * procedure as soon as both sides of the channel have seen EOF.
     */
    return sent_local_eof && rcvd_remote_eof;
}

bool chan_no_exit_status(__attribute__((unused)) Channel *chan,
                         __attribute__((unused)) int status)
{
    return false;
}

bool chan_no_exit_signal(__attribute__((unused)) Channel *chan,
                         __attribute__((unused)) ptrlen signame,
                         __attribute__((unused)) bool core_dumped,
                         __attribute__((unused)) ptrlen msg)
{
    return false;
}

bool chan_no_exit_signal_numeric(__attribute__((unused)) Channel *chan,
                                 __attribute__((unused)) int signum,
                                 __attribute__((unused)) bool core_dumped,
                                 __attribute__((unused)) ptrlen msg)
{
    return false;
}

bool chan_no_run_shell(__attribute__((unused)) Channel *chan)
{
    return false;
}

bool chan_no_run_command(__attribute__((unused)) Channel *chan,
                         __attribute__((unused)) ptrlen command)
{
    return false;
}

bool chan_no_run_subsystem(__attribute__((unused)) Channel *chan,
                           __attribute__((unused)) ptrlen subsys)
{
    return false;
}

bool chan_no_enable_x11_forwarding(__attribute__((unused)) Channel *chan,
                                   __attribute__((unused)) bool oneshot,
                                   __attribute__((unused)) ptrlen authproto,
                                   __attribute__((unused)) ptrlen authdata,
                                   __attribute__((unused)) unsigned screen_number)
{
    return false;
}

bool chan_no_enable_agent_forwarding(__attribute__((unused)) Channel *chan)
{
    return false;
}

bool chan_no_allocate_pty(__attribute__((unused)) Channel *chan,
                          __attribute__((unused)) ptrlen termtype,
                          __attribute__((unused)) unsigned width,
                          __attribute__((unused)) unsigned height,
                          __attribute__((unused)) unsigned pixwidth,
                          __attribute__((unused)) unsigned pixheight,
                          __attribute__((unused)) struct ssh_ttymodes modes)
{
    return false;
}

bool chan_no_set_env(__attribute__((unused)) Channel *chan,
                     __attribute__((unused)) ptrlen var,
                     __attribute__((unused)) ptrlen value)
{
    return false;
}

bool chan_no_send_break(__attribute__((unused)) Channel *chan,
                        __attribute__((unused)) unsigned length)
{
    return false;
}

bool chan_no_send_signal(__attribute__((unused)) Channel *chan,
                         __attribute__((unused)) ptrlen signame)
{
    return false;
}

bool chan_no_change_window_size(__attribute__((unused)) Channel *chan,
                                __attribute__((unused)) unsigned width,
                                __attribute__((unused)) unsigned height,
                                __attribute__((unused)) unsigned pixwidth,
                                __attribute__((unused)) unsigned pixheight)
{
    return false;
}

void chan_no_request_response(__attribute__((unused)) Channel *chan,
                              __attribute__((unused)) bool success)
{
    unreachable("this channel type should never send a want-reply request");
}

/* ----------------------------------------------------------------------
 * Other miscellaneous utility functions.
 */

void free_rportfwd(struct ssh_rportfwd *rpf)
{
    if (rpf)
    {
        sfree(rpf->log_description);
        sfree(rpf->shost);
        sfree(rpf->dhost);
        sfree(rpf);
    }
}
