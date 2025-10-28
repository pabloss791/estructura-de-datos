#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  

// Creación de la estructura de Objetos con los datos que tiene
typedef struct {
    char object_name[20];
    int affected_attribute;// Este será el que eliga que atributo mejorará
    int power; // Acá elegira cuantos puntos subira
} Object;


// Creación dela estructura de Personajes con los datos que tiene
typedef struct {
    char character_name[20];
    int HP;
    int Damage;
    int physical_attack;
    int magical_attack;
    int physical_defense;
    int magical_defense;
    void (*magics[3])(void *, void *); // Se hace un arreglo de 3 punteros a función para las magias
    char *magic_names[3];
    int buff_turns;
    int lost_turn;
    int evade;
    Object *inventory[3]; // Arreglo de apuntadores de tipo objeto
} Characters;


// Creación de las magias
void Darkness_Shield(void *caster_void, void*target_void){
    Characters *p = (Characters *)caster_void;
    p->physical_defense +=4;
    p->magical_defense += 4;
    p->buff_turns = 3;

    printf("\n====================================\n");
    printf("%s usa Darkness Shield\n", p->character_name);
    printf("Sus defensas aumentan 4 puntos\n");
    printf("Efecto dura 3 turnos\n");
    printf("====================================\n\n");

}

void Paralyze(void *caster_void, void*target_void){
    Characters *caster = (Characters *)caster_void;
    Characters *target = (Characters *)target_void;

    if(caster->magical_attack > target->magical_defense) {
        target->lost_turn = 1;
        printf("\n====================================\n");
        printf("%s ha paralizado a %s\n", caster->character_name, target->character_name);
        printf("%s pierde un turno\n", target->character_name);
        printf("====================================\n\n");
    } else {
        printf("\n====================================\n");
        printf("%s ha resistido la magia\n", target->character_name);
        printf("====================================\n\n");
    }

}

void Fire_Ball(void *caster_void, void*target_void){
    Characters *caster = (Characters *)caster_void;
    Characters *target = (Characters *)target_void;

    if(caster->magical_attack > target->magical_defense) {
        int Damage_Caused =  caster->magical_attack;
        target->Damage += Damage_Caused;

        printf("\n====================================\n");
        printf("%s ha lanzado Fire Ball a %s\n", caster->character_name, target->character_name);
        printf("%s ha recibido %d puntos de daño\n", target->character_name, Damage_Caused);
        printf("Vida restante de %s: %d\n", target->character_name, target->HP - target->Damage);
        printf("====================================\n\n");
    } else{
        printf("\n====================================\n");
        printf("Fire Ball ha fallado\n");
        printf("%s resistió el ataque sin daño\n", target->character_name);
        printf("====================================\n\n");
    }

}

    void Magic_Missile(void *caster_void, void*target_void){
        Characters *caster = (Characters *)caster_void;
        Characters *target = (Characters *)target_void;

        if(caster->magical_attack > target->magical_defense) {
            int Damage_Caused = caster->magical_attack;
            target->Damage += Damage_Caused;

            printf("\n====================================\n");
            printf("%s ha lanzado Magic Missile a %s\n", caster->character_name, target->character_name);
            printf("%s ha recibido %d puntos de daño\n", target->character_name, Damage_Caused);
            printf("Vida restante de %s: %d\n", target->character_name, target->HP - target->Damage);
            printf("====================================\n\n");
        }
    }    

void Heal(void *caster_void, void*target_void){
    Characters *p = (Characters *)caster_void;
    int heal_pts = 5;
    int super_heal = rand() % 15;

    if(super_heal == 0){
        heal_pts = 20;
        printf("\n====================================\n");
        printf("¡CRÍTICO! La diosa Aqua te ha ayudado\n");
        printf("Recibes curación máxima\n");
        printf("====================================\n\n");
    }

    p->Damage -= heal_pts;

    if(p->Damage < 0) {
        p->Damage = 0;
    }

    printf("\n====================================\n");
    printf("%s uso Heal\n", p->character_name);
    printf("Recupera %d puntos de vida\n", heal_pts);
    printf("Vida restante: %d\n", p->HP - p->Damage);
    printf("====================================\n\n");

}


// Se inicializa los atributos del personaje
void Initialize_character(Characters *p, const char *name, int hp, int pa, int ma, int pd, int md){
    strcpy(p->character_name, name);
    p->HP = hp;
    p->Damage = 0;
    p->physical_attack = pa;
    p->magical_attack = ma;
    p->physical_defense = pd;
    p->magical_defense = md;
    for(int i = 0; i < 3; i++) {
        p->inventory[i] = NULL;
     }
}

Object *aleatory_object(){
    Object *new_object =(Object *)malloc(sizeof(Object));
    if(new_object == NULL) {
        printf("Error: No hay espacio para el objeto\n");
        exit(1);
    }

    char *object_names[] = {"Poción", "Excalibur", "Lanza de Longinus", "Incursio", "Amuleto mágico"};

    int name_index = rand() % 5;
    strcpy(new_object->object_name, object_names[name_index]);

    switch(name_index){
        case 0:
            new_object->affected_attribute = 0;
            new_object->power = 10;
            break;
        case 1:
            new_object->affected_attribute = 1;
            new_object->power = 15;
            break;
        case 2:
            new_object->affected_attribute = 1;
            new_object->power = 10;
            break;
        case 3:
            new_object->affected_attribute = 3;
            new_object->power = 10;
            break;
        case 4:
            new_object->affected_attribute = 2;
            new_object->power = 10;
            break;
    }
    return new_object;
}


void stats_enemies(Characters * p, const char *name, int hp, int pa, int pd, int ma, int md){
    strcpy(p->character_name, name);
    p->HP = hp;
    p->Damage = 0;
    p->physical_attack = pa;
    p->physical_defense = pd;
    p->magical_attack = ma;
    p->magical_defense = md;
    p->buff_turns = 0;
    p->lost_turn = 0;
    for(int i = 0; i < 3; i++){
        p->inventory[i] = NULL;
    }
}

char *game_magics_names[] = {"Darkness Shield", "Paralyze", "Fire Ball", "Magic Missile", "Heal"};   
void (*game_magics[])(void*, void*) = {Darkness_Shield, Paralyze, Fire_Ball, Magic_Missile, Heal};

void Inizialize_enemies(Characters *enemies) {
 int num_magics = 5;
 int magic_index[5];

 char *enemies_name[] = {"Kobold", "Dark Elf", "Dragon", "Rey Demonio"};
 int enemies_objects[] = {0, 0, 0, 0};

stats_enemies(&enemies[0], "Kobold", 10, 15, 8, 5, 3);
stats_enemies(&enemies[1], "Dark Elf", 15, 10, 10, 15, 10);
stats_enemies(&enemies[2], "Dragón", 20, 15, 15, 10, 10);
stats_enemies(&enemies[3], "Rey Demonio", 30, 15, 15, 15, 15);

 for(int i = 0; i < 4; i++){

    for(int k = 0; k < num_magics; k++){
        magic_index[k] = k;
    }

    for(int j = 0; j < 3; j++){
        int aleatory_index = rand() % (num_magics - j);
        int index_random_magic = magic_index[aleatory_index];
        
        (enemies + i)->magics[j] = game_magics[index_random_magic];
        (enemies + i)->magic_names[j] = game_magics_names[index_random_magic];
        
        int temp = magic_index[aleatory_index];
        *(magic_index + aleatory_index) = magic_index[num_magics -1 -j];
        *(magic_index + num_magics -1 -j) = temp;
    }

    for(int j = 0; j < enemies_objects[i]; j++){
        (enemies + i)->inventory[j] = aleatory_object();
    }
 }
}

void free_objects(Object **Objects, int number) {
    for(int i = 0; i < number; i++){
        if(Objects[i] != NULL) {
            free(Objects[i]);
            Objects[i] = NULL;
        }
    }
}


void turn_effects(Characters *p){
    if(p->buff_turns > 0){
        p->buff_turns--;
        
        if(p->buff_turns == 0){
            printf("\n====================================\n");
            printf("El efecto de Darkness Shield ha acabado\n");
            printf("Defensas vuelven a la normalidad\n");
            printf("====================================\n\n");
            p->physical_defense -= 4;
            p->magical_defense -= 4;
        }
    }
}

void player_inventory(Characters *player){
    int choice;
    int items = 0;

    printf("\n====================================\n");
    printf("          INVENTARIO\n");
    printf("====================================\n");
    for(int i = 0; i < 3; i++){
        if(*(player->inventory + i) != NULL){
            printf("%d) %s (beneficio: +%d)\n", i + 1, (*(player->inventory + i))->object_name, (*(player->inventory + i))->power);
            items++;
        }
    }

    if(items == 0){
        printf("Inventario vacío\n");
        printf("====================================\n\n");
        return;
    }

    printf("====================================\n");
    printf("¿Qué objeto quieres usar? ");
    scanf("%d", &choice);

    if(choice >= 1 && choice <= 3 && *(player->inventory + (choice - 1)) != NULL){
        Object *used_item = *(player->inventory + (choice - 1));

        printf("\n====================================\n");
        switch(used_item->affected_attribute){
            case 0:
                player->Damage -= used_item->power;
                if(player->Damage < 0) player->Damage = 0;
                printf("%s ha usado %s\n", player->character_name, used_item->object_name);
                printf("Recupera %d de HP\n", used_item->power);
                printf("Vida restante: %d\n", player->HP - player->Damage);
                break;
            case 1:
                player->physical_attack += used_item->power;
                printf("%s ha usado %s\n", player->character_name, used_item->object_name);
                printf("Ataque físico aumenta +%d puntos\n", used_item->power);
                break;
            case 2:
                player->magical_attack += used_item->power;
                printf("%s ha usado %s\n", player->character_name, used_item->object_name);
                printf("Ataque mágico aumenta +%d puntos\n", used_item->power);
                break;
            case 3:
                player->physical_defense += used_item->power;
                player->magical_defense += used_item->power;
                printf("%s ha usado %s\n", player->character_name, used_item->object_name);
                printf("Ambas defensas aumentan +%d puntos\n", used_item->power);
                break;
        }
        printf("====================================\n\n");

        free(used_item);
        *(player->inventory + (choice - 1)) = NULL;
    } else{
        printf("\n====================================\n");
        printf("Opción inválida\n");
        printf("====================================\n\n");
    }
}

void add_item(Characters *player, Object *new_item){
    int free_slot = -1;
    int choice;
    
    for(int i = 0; i < 3; i++){
        if(*(player->inventory + i) == NULL){
            free_slot = i;
            break;
        }
    }
    
    if(free_slot != -1){
        *(player->inventory + free_slot) = new_item;
        printf("\n====================================\n");
        printf("%s ha añadido %s al inventario\n", player->character_name, new_item->object_name);
        printf("====================================\n\n");
        
        switch(new_item->affected_attribute){
            case 0:
                player->HP += new_item->power;
                break;
            case 1:
                player->physical_attack += new_item->power;
                break;
            case 2:
                player->magical_attack += new_item-> power;
                break;
            case 3:
                player->physical_defense += new_item-> power;
                player->magical_defense += new_item-> power;
                break;
        }
    } else {
        printf("\n====================================\n");
        printf("INVENTARIO LLENO\n");
        printf("Elige un objeto para eliminar:\n");
        printf("====================================\n");
        
        for(int i = 0; i < 3; i++){
            printf("%d) %s (beneficio: +%d)\n", i + 1, (*(player->inventory + i))->object_name, (*(player->inventory + i))->power);
        }
        
        printf("====================================\n");
        printf("Selecciona el objeto que deseas eliminar: ");
        scanf("%d", &choice);
        
        if(choice >= 1 && choice <= 3){
            Object *remove_item = *(player->inventory + (choice -1));
            
            if(strcmp(remove_item->object_name, "Poción") == 0){    
            } else if (strcmp(remove_item->object_name, "Excalibur") == 0 ){
                player->physical_attack -=15;
            } else if (strcmp(remove_item->object_name, "Lanza de Longinus") == 0 ){
                player->physical_attack -= 10;
            } else if(strcmp(remove_item->object_name, "Incursio") == 0 ){
                player->physical_defense -= 10;
                player->magical_defense -= 10;
            } else if(strcmp(remove_item->object_name, "Amuleto magico") == 0 ){
                player->magical_attack -= 10;
            }
            
            free(remove_item);
            
            *(player->inventory + (choice - 1)) = new_item;
            printf("\n====================================\n");
            printf("%s añadido al inventario\n", new_item->object_name);
            printf("====================================\n\n");
            
            switch(new_item->affected_attribute){
                case 0:
                    player->HP += new_item->power;
                    break;
                case 1:
                    player->physical_attack += new_item->power;
                    break;
                case 2:
                    player->magical_attack += new_item-> power;
                    break;
                case 3:
                    player->physical_defense += new_item-> power;
                    player->magical_defense += new_item-> power;
                    break;
            }
        }
    }
}

void rewards(Characters *player) {
    printf("\n====================================\n");
    printf("          RECOMPENSAS\n");
    printf("====================================\n");
    printf("%s ha encontrado un tesoro\n", player->character_name);
    printf("Puede llevarse 2 objetos como recompensa\n");
    printf("====================================\n\n");
    
    Object *battle_rewards[4];

    for(int i = 0; i < 4; i++) {
        *(battle_rewards + i) = aleatory_object();
        printf("%d) %s (Poder: +%d)\n", i + 1, (*(battle_rewards + i))->object_name, (*(battle_rewards + i))->power);
    }

    for(int i = 0; i < 2; i++){
        int choice;
        printf("\nSelecciona el objeto %d que quieres: ", i + 1);
        if(scanf("%d", &choice) != 1) continue;

        if(choice >= 1 && choice <= 4 && *(battle_rewards + (choice - 1)) != NULL){
            add_item(player, *(battle_rewards + (choice -1)));
            
            *(battle_rewards + (choice -1)) = NULL;
        } else {
            printf("\n====================================\n");
            printf("Opción inválida, intente de nuevo\n");
            printf("====================================\n\n");
            i--;
        }
    }
    
    for(int i = 0; i < 4; i ++){
        if(*(battle_rewards + i) != NULL){
            free(*(battle_rewards + i));
        } 
    }
}

void magics_player(Characters *player, Characters *enemy){
    printf("\n====================================\n");
    printf("          SELECCIÓN DE MAGIA\n");
    printf("====================================\n");
    printf("Elige tu magia:\n");
    for(int i = 0; i < 3; i++){
        printf("%d) %s\n", i+1, *(player->magic_names + i));
    }
    printf("====================================\n");
    printf("Opción: ");
    
    int choice;
    scanf("%d", &choice);
    
    if(choice >= 1 && choice <= 3){
        void (*magic_use)(void*, void*) = player->magics[choice - 1];
        magic_use(player, enemy);
    }
}

void evade_attack(Characters *p){
    if(rand() % 2 == 0){
        p->evade = 1;
        printf("\n====================================\n");
        printf("%s se prepara para evadir\n", p->character_name);
        printf("Bloqueará el siguiente ataque del rival\n");
        printf("====================================\n\n");
    } else {
        p->evade = 0;
        printf("\n====================================\n");
        printf("%s intentó evadir pero falló\n", p->character_name);
        printf("====================================\n\n");
    }
}

void physical_attack(Characters *attacker, Characters *Opponent){
    if(Opponent->evade == 1){
        printf("\n====================================\n");
        printf("%s ha evadido el ataque exitosamente\n", Opponent->character_name);
        printf("====================================\n\n");
        Opponent->evade = 0;
        return;
    }
    
    int Damage_caused = attacker->physical_attack -  Opponent->physical_defense;
    if(Damage_caused < 0){
        Damage_caused = 0;
    }
    Opponent->Damage += Damage_caused;
    
    printf("\n====================================\n");
    printf("%s atacó a %s\n", attacker->character_name, Opponent->character_name);
    printf("Daño causado: %d puntos\n", Damage_caused);
    printf("Vida restante de %s: %d\n", Opponent->character_name, Opponent->HP - Opponent->Damage);
    printf("====================================\n\n");
}

void player_turn(Characters *player, Characters *enemy){
    printf("\n====================================\n");
    printf("       TURNO DE %s\n", player->character_name);
    printf("====================================\n");
    printf("1. Ataque Físico\n");
    printf("2. Magia\n");
    printf("3. Objetos\n");
    printf("4. Evasión\n");
    printf("====================================\n");
    printf("Elige tu acción: ");

    int choice;
    scanf("%d", &choice);

    switch(choice){
        case 1:
            physical_attack(player, enemy);
            break;
        case 2:
            magics_player(player, enemy);
            break;
        case 3:
            player_inventory(player);
            break;
        case 4:
            evade_attack(player);
            break;
    }
}

void enemy_turn(Characters *enemy, Characters *player){
    printf("\n====================================\n");
    printf("       TURNO DE %s\n", enemy->character_name);
    printf("====================================\n");

    if(enemy->lost_turn > 0){
        printf("%s está paralizado y no puede moverse\n", enemy->character_name);
        printf("====================================\n\n");
        enemy->lost_turn = 0;
        return;
    }
    
    int choice = rand() % 3;

    switch(choice){
        case 0:
            physical_attack(enemy, player);
            break;
        case 1:
            enemy->magics[rand() % 3](enemy, player);
            break;
        case 2:
            evade_attack(enemy);
            break;
    }
}

void battle (Characters *player, Characters *enemy){
    printf("\n====================================\n");
    printf("          COMIENZA LA BATALLA\n");
    printf("====================================\n");
    printf("%s se enfrenta a %s\n", player->character_name, enemy->character_name);
    printf("de las fuerzas del Señor Oscuro\n");
    printf("====================================\n\n");
    
    while(player->HP - player->Damage > 0 && enemy->HP - enemy->Damage > 0){
        player_turn(player, enemy);
        turn_effects(enemy);
        
        if(enemy->HP - enemy->Damage <= 0){
            printf("\n====================================\n");
            printf("          VICTORIA\n");
            printf("====================================\n");
            printf("%s ha ganado la batalla\n", player->character_name);
            printf("%s ha sido derrotado\n", enemy->character_name);
            printf("====================================\n\n");
            break;
        }

        enemy_turn(enemy,player);
        turn_effects(player);

        if(player->HP - player->Damage <= 0) {
            printf("\n====================================\n");
            printf("          DERROTA\n");
            printf("====================================\n");
            printf("%s te ha derrotado\n", enemy->character_name);
            printf("FIN DEL JUEGO\n");
            printf("====================================\n\n");
        }
    }
}

int main() {
    srand(time(NULL));
    Characters players[5];
    char name_buffer[50];
    int choice;

    int player_hp = 20;
    int player_pa = 15;
    int player_ma = 10;
    int player_pd = 10;
    int player_md = 10;

    printf("================================================================================\n");
    printf("                  BIENVENIDO AL MUNDO DE AVENTURAS\n");
    printf("================================================================================\n");
    printf("Bienvenido, mi nombre es Aqua la diosa de este mundo.\n");
    printf("Te he traído para que liberes el mundo de las garras del malvado Rey Demonio.\n");
    printf("Así que dime, héroe...\n");
    printf("================================================================================\n\n");

    printf("====================================\n");
    printf("          CREACIÓN DE HÉROE\n");
    printf("====================================\n");
    printf("¿Cuál es tu nombre? ");
    fgets(name_buffer, sizeof(name_buffer), stdin);
    name_buffer[strcspn(name_buffer, "\n")] = 0;
    printf("====================================\n\n");

    Initialize_character(&players[0], name_buffer, player_hp, player_pa, player_ma, player_pd, player_md);
    
    printf("====================================\n");
    printf("          SELECCIÓN DE MAGIAS\n");
    printf("====================================\n");
    printf("Te daré 3 magias para que puedas derrotarlo.\n");
    printf("Selecciona las que quieras:\n");
    printf("====================================\n");
    for (int i = 0; i < 5; i++) {
        printf("%d) %s\n", i + 1, game_magics_names[i]);
    }
    printf("====================================\n");
    
    for (int i = 0; i < 3; i++) {
        printf("Selecciona la Magia %d: ", i + 1);
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
            printf("Elección inválida, selecciona una correcta\n");
            i--;
            while(getchar() != '\n');
            continue;
        }
        players[0].magics[i] = game_magics[choice - 1];
        players[0].magic_names[i] = game_magics_names[choice - 1];
    }
    while(getchar() != '\n'); 

    // Inicialización de enemigos
    Inizialize_enemies(&players[1]); 

    printf("\n================================================================================\n");
    printf("                 TU AVENTURA HA COMENZADO\n");
    printf("================================================================================\n\n");

    for (int i = 0; i < 4; i++) {
        Characters *current_enemy = &players[1 + i];

        printf("\n================================================================================\n");
        printf("                    BATALLA %d\n", i + 1);
        printf("================================================================================\n");
        printf("Te has encontrado con %s\n", current_enemy->character_name);
        printf("La batalla comienza...\n");
        printf("================================================================================\n\n");
        
        battle(&players[0], current_enemy);

        if (players[0].HP - players[0].Damage <= 0) {
            printf("\n================================================================================\n");
            printf("                    GAME OVER\n");
            printf("================================================================================\n");
            printf("Has caído ante el ejército del Rey Demonio.\n");
            printf("La aventura ha terminado.\n");
            printf("================================================================================\n\n");
            break; 
        }

        if (i < 3) {
            printf("\n================================================================================\n");
            printf("                    VICTORIA\n");
            printf("================================================================================\n");
            printf("¡%s ha ganado la batalla!\n", players[0].character_name);
            printf("================================================================================\n\n");
            rewards(&players[0]);
        } else {
            printf("\n================================================================================\n");
            printf("                    VICTORIA FINAL\n");
            printf("================================================================================\n");
            printf("¡FELICIDADES HÉROE!\n");
            printf("Has derrotado al Rey Demonio y salvado el mundo.\n");
            printf("================================================================================\n\n");
        }
    }

    for (int i = 0; i < 5; i++) {
         free_objects(players[i].inventory, 3);
    }
    
    return 0;
}