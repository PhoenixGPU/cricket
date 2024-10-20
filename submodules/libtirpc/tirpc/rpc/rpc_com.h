/*	$NetBSD: rpc_com.h,v 1.3 2000/12/10 04:10:08 christos Exp $	*/
/*	$FreeBSD: src/include/rpc/rpc_com.h,v 1.6 2003/01/16 07:13:51 mbr Exp $ */

/*
 * Copyright (c) 2009, Sun Microsystems, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name of Sun Microsystems, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * Copyright (c) 1986 - 1991 by Sun Microsystems, Inc.
 */

/*
 * rpc_com.h, Common definitions for both the server and client side.
 * All for the topmost layer of rpc
 *
 */

#ifndef _RPC_RPCCOM_H
#define	_RPC_RPCCOM_H


/* #pragma ident	"@(#)rpc_com.h	1.11	93/07/05 SMI" */

/*
 * The max size of the transport, if the size cannot be determined
 * by other means.
 */
#define	RPC_MAXDATASIZE 9000
#define	RPC_MAXADDRSIZE 1024

#define __RPC_GETXID(now) ((u_int32_t)getpid() ^ (u_int32_t)(now)->tv_sec ^ \
    (u_int32_t)(now)->tv_usec)

#ifdef __cplusplus
extern "C" {
#endif
extern u_int __rpc_get_a_size(int);
extern int __rpc_dtbsize(void);
extern int _rpc_dtablesize(void);
extern struct netconfig * __rpcgettp(int);

char *__rpc_taddr2uaddr_af(int, const struct netbuf *);
struct netbuf *__rpc_uaddr2taddr_af(int, const char *);
int __rpc_fixup_addr(struct netbuf *, const struct netbuf *);
int __rpc_sockinfo2netid(struct __rpc_sockinfo *, const char **);
int __rpc_seman2socktype(int);
int __rpc_socktype2seman(int);
void *rpc_nullproc(CLIENT *);
int __rpc_sockisbound(int);

struct netbuf *__rpcb_findaddr(rpcprog_t, rpcvers_t, const struct netconfig *,
			       const char *, CLIENT **);
bool_t rpc_control(int,void *);

#ifdef __cplusplus
}
#endif

extern  int  __rpc_get_default_domain(char **);
char *_get_next_token(char *, int);

#ifndef MEASUREMENT_DETAILED
#define MEASUREMENT_DETAILED

// #define MEASUREMENT_DETAILED_SWITCH

#include <sys/time.h>
#include <time.h>

#define TIMETYPE 3
enum {
    TOTAL_TIME = 0,
    SERIALIZATION_AND_NETWORK_TIME,
    NETWORK_TIME
};

typedef struct _detailed_info {
    int id;
    int cnt;
    long long time[TIMETYPE];
    struct timeval start[TIMETYPE], end[TIMETYPE];
    long long payload_size;
} detailed_info;

#define API_COUNT 6000

void add_cnt(detailed_info *infos, int id);
void set_start(detailed_info *infos, int id, int type, struct timeval *start);
void set_end(detailed_info *infos, int id, int type, struct timeval *end);
void time_start(detailed_info *infos, int id, int type);
void time_end(detailed_info *infos, int id, int type);
void add_payload_size(detailed_info *infos, int id, long long size);
void print_detailed_info(detailed_info *infos, int length, const char* str);

#endif

#endif /* _RPC_RPCCOM_H */
