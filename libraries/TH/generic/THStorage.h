#ifndef TH_GENERIC_FILE
#define TH_GENERIC_FILE "generic/THStorage.h"
#else

/* on pourrait avoir un liste chainee
   qui initialise math, lab structures (or more).
   mouais -- complique.

   Pb: THMapStorage is kind of a class
   THLab_()... comment je m'en sors?
   
   en template, faudrait que je les instancie toutes!!! oh boy!
   Et comment je sais que c'est pour Cuda? Le type float est le meme dans les <>
   
   au bout du compte, ca serait sur des pointeurs float/double... etc... = facile.
   primitives??
 */

typedef struct THStorage
{
    real *data;
    long size;
    int refcount;
    char isMapped;

} THStorage;

TH_API real* THStorage_(data)(THStorage*);
TH_API long THStorage_(size)(THStorage*);

/* slow access -- checks everything */
TH_API void THStorage_(set)(THStorage*, long, real);
TH_API real THStorage_(get)(THStorage*, long);

TH_API THStorage* THStorage_(new)(void);
TH_API THStorage* THStorage_(newWithSize)(long size);
TH_API THStorage* THStorage_(newWithSize1)(real);
TH_API THStorage* THStorage_(newWithSize2)(real, real);
TH_API THStorage* THStorage_(newWithSize3)(real, real, real);
TH_API THStorage* THStorage_(newWithSize4)(real, real, real, real);
TH_API THStorage* THStorage_(newWithMapping)(const char *fileName, int isShared);

/* should not differ with API */
TH_API void THStorage_(retain)(THStorage *storage);

/* might differ with other API (like CUDA) */
TH_API void THStorage_(free)(THStorage *storage);
TH_API void THStorage_(resize)(THStorage *storage, long size);
TH_API void THStorage_(rawCopy)(THStorage *storage, real *src);
TH_API void THStorage_(copy)(THStorage *storage, THStorage *src);
TH_API void THStorage_(fill)(THStorage *storage, real value);

/* Support for copy between different Storage types */

struct THByteStorage;
struct THCharStorage;
struct THShortStorage;
struct THIntStorage;
struct THLongStorage;
struct THFloatStorage;
struct THDoubleStorage;

TH_API void THStorage_(copyByte)(THStorage *storage, struct THByteStorage *src);
TH_API void THStorage_(copyChar)(THStorage *storage, struct THCharStorage *src);
TH_API void THStorage_(copyShort)(THStorage *storage, struct THShortStorage *src);
TH_API void THStorage_(copyInt)(THStorage *storage, struct THIntStorage *src);
TH_API void THStorage_(copyLong)(THStorage *storage, struct THLongStorage *src);
TH_API void THStorage_(copyFloat)(THStorage *storage, struct THFloatStorage *src);
TH_API void THStorage_(copyDouble)(THStorage *storage, struct THDoubleStorage *src);

#endif
