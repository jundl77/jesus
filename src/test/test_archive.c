#define EFL_BETA_API_SUPPORT
#define EFL_EO_API_SUPPORT

#include <Elementary.h>
#include "Efm.h"

int
main(int argc EINA_UNUSED, char **argv EINA_UNUSED)
{
   if (!efm_archive_file_extract("Abschluss.zip", "/tmp/"))
     {
        printf("FAILED!! %s\n", efm_archive_lasterror_get());
     }
   else
     {
        printf("SUCCESS\n");
     }

   return 1;
}
