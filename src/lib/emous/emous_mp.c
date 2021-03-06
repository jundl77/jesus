#include "emous_priv.h"

int EMOUS_MOUNT_DEL;
int EMOUS_MOUNT_ADD;

typedef struct {
   Emous_Device_Type *class;
   const char *mount_point;
   const char *source;
} Mount_Point;

static Eina_Hash *mount_points;

void
_emous_mount_add(const char *type, const char *mount_point, const char *source)
{
   Mount_Point *m;
   Emous_Device_Type *c;

   DBG("Adding %s %s %s", type, mount_point, source);

   eo_do(EMOUS_MANAGER_CLASS, c = emous_manager_device_type_get(type));

   if (!c)
     {
        DBG("Noone cared about type %s. ...dropping!", type);
        return;
     }

   m = calloc(1, sizeof(Mount_Point));
   m->class = c;
   m->source = eina_stringshare_add(source);
   m->mount_point = eina_stringshare_add(mount_point);

   eo_do(c, emous_device_type_mountpoint_added(m->mount_point, m->source));

   eina_hash_add(mount_points, m->mount_point, m);
}

void
_emous_mount_del(const char *mount_point)
{
   Mount_Point *mp;
   const char *mnt_point = eina_stringshare_add(mount_point);

   DBG("Deleting %s", mnt_point);

   mp = eina_hash_find(mount_points, mnt_point);

   //check if this mountpoint is registered or not
   if (!mp)
     return;

   eo_do(mp->class, emous_device_type_mountpoint_removed(mnt_point));

   eina_hash_del(mount_points, mnt_point, mp);
}

static void
_free_cb(void *data)
{
   Mount_Point *p;

   p = data;

   eina_stringshare_del(p->mount_point);
   eina_stringshare_del(p->source);
   free(p);
}

void
_emous_mount_point_init(void)
{
   mount_points = eina_hash_stringshared_new(_free_cb);
}

void
_emous_mount_point_shutdown(void)
{
   eina_hash_free(mount_points);
}
