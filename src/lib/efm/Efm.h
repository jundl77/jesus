#ifndef EIO_FM_H
#define EIO_FM_H

#include <Eina.h>
#include <Eo.h>

#ifdef EFL_BETA_API_SUPPORT
# include "efm_file.eo.h"
# include "efm_monitor.eo.h"
#else
# include "efm_file.eo.legacy.h"
# include "efm_monitor.eo.legacy.h"
#endif

/*
 * Inits the fm_monitor
 */
EAPI int efm_init();
/*
  shutdown the fm_monitor
 */
EAPI void efm_shutdown();
/*
 * Efm archive stuff
 */

EAPI Eina_Bool efm_archive_file_supported(const char *fileending);

EAPI Eina_Bool efm_archive_file_extract(const char *file, const char *goal);

EAPI const char *efm_archive_lasterror_get(void);

#endif