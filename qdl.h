#ifndef __QDL_H__
#define __QDL_H__

#include <stdbool.h>

#include "patch.h"
#include "program.h"
#include <libxml/tree.h>

struct qdl_device;

int qdl_read(struct qdl_device *qdl, void *buf, size_t len, unsigned int timeout);
int qdl_write(struct qdl_device *qdl, const void *buf, size_t len, bool eot);

int firehose_open(struct qdl_device *qdl, bool ufs);
int firehose_run(struct qdl_device *qdl, const char *incdir, const char *storage);
int sahara_run(struct qdl_device *qdl, char *prog_mbn);
void print_hex_dump(const char *prefix, const void *buf, size_t len);
unsigned attr_as_unsigned(xmlNode *node, const char *attr, int *errors);
const char *attr_as_string(xmlNode *node, const char *attr, int *errors);

int firehose_getsize(struct qdl_device *qdl, int lun, size_t *sector_size,
                     size_t *num_sectors);
int firehose_reset(struct qdl_device *qdl);

extern bool qdl_debug;

#endif
