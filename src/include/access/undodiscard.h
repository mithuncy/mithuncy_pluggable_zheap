/*-------------------------------------------------------------------------
 *
 * undoinsert.h
 *	  undo discard definitions
 *
 * Portions Copyright (c) 1996-2017, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/access/undodiscard.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef UNDODISCARD_H
#define UNDODISCARD_H

#include "access/undolog.h"
#include "access/undorecord.h"
#include "access/xlogdefs.h"
#include "catalog/pg_class.h"

/*
 * Discard the undo for all the transaction whose xid is smaller than xmin
 *
 *	Check the DiscardInfo memory array for each slot (every undo log) , process
 *	the undo log for all the slot which have xid smaller than xmin or invalid
 *	xid. Fetch the record from the undo log transaction by transaction until we
 *	find the xid which is not smaller than xmin.
 */
extern void UndoDiscard(TransactionId xmin);

/* Compute shared memory space needed for undolog discard information. */
extern Size UndoDiscardShmemSize(void);

/* Initialize the undo discard shared mem structure. */
extern void UndoDiscardShmemInit(void);

#endif   /* UNDODISCARD_H */
