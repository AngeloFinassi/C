#include <stdio.h>
#include <allegro5/allegro.h>

int main() {
   ALLEGRO_CONFIG* cfg = al_load_config_file("test.cfg");
    printf("%s\n", al_get_config_value(cfg, "", "monster name")); /* Prints: Allegro Developer */
    printf("%s\n", al_get_config_value(cfg, "weapon 0", "damage")); /* Prints: 443 */
    printf("%s\n", al_get_config_value(cfg, "weapon 1", "damage")); /* Prints: 503 */
    al_destroy_config(cfg);
}
