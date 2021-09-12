/*
 * nullplug.c: provide a null implementation of the Plug vtable which
 * ignores all calls. Occasionally useful in cases where we want to
 * make a network connection just to see if it works, but not do
 * anything with it afterwards except close it again.
 */

#include "putty.h"

static void nullplug_socket_log(__attribute__((unused)) Plug *plug,
                                __attribute__((unused)) PlugLogType type,
                                __attribute__((unused)) SockAddr *addr,
                                __attribute__((unused)) int port,
                                __attribute__((unused)) const char *err_msg,
                                __attribute__((unused)) int err_code)
{
}

static void nullplug_closing(__attribute__((unused)) Plug *plug,
                             __attribute__((unused)) const char *error_msg,
                             __attribute__((unused)) int error_code,
                             __attribute__((unused)) bool calling_back)
{
}

static void nullplug_receive(__attribute__((unused)) Plug *plug,
                             __attribute__((unused)) int urgent,
                             __attribute__((unused)) const char *data,
                             __attribute__((unused)) size_t len)
{
}

static void nullplug_sent(__attribute__((unused)) Plug *plug,
                          __attribute__((unused)) size_t bufsize)
{
}

static const PlugVtable nullplug_plugvt = {
    .log = nullplug_socket_log,
    .closing = nullplug_closing,
    .receive = nullplug_receive,
    .sent = nullplug_sent,
};

static Plug nullplug_plug = {&nullplug_plugvt};

/*
 * There's a singleton instance of nullplug, because it's not
 * interesting enough to worry about making more than one of them.
 */
Plug *const nullplug = &nullplug_plug;
