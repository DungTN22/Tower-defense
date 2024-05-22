#include "include file.cpp"
SDL_Window *window= SDL_CreateWindow("Tower Defense",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1400,800,SDL_WINDOW_SHOWN);
    
SDL_Event event;

SDL_Renderer *render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

// suface start screen
SDL_Surface *background_loading=IMG_Load("sprites img/GUI img/Preview1.jpg");
SDL_Surface *loading_size=IMG_Load("sprites img/GUI img/loading_stick.png");
SDL_Surface *loading_size_speed=IMG_Load("sprites img/GUI img/loading.png");
SDL_Surface *warning_load=IMG_Load("sprites img/GUI img/warning table.png");
SDL_Surface *hp_thanh=IMG_Load("sprites img/GUI img/hp.png");

// surface enter name screen
SDL_Surface *background_entering=IMG_Load("sprites img/GUI img/background1.png");
SDL_Surface *enter_table=IMG_Load("sprites img/GUI img/menu.png");
SDL_Surface *title=IMG_Load("sprites img/GUI img/title.png");

// surface home screen
SDL_Surface *background_home=IMG_Load("sprites img/GUI img/background3.png");
SDL_Surface *table_level=IMG_Load("sprites img/GUI img/level table.png");

SDL_Surface *gate_open=IMG_Load("sprites img/GUI img/gate open.png");
SDL_Surface *gate_close=IMG_Load("sprites img/GUI img/window mode.png");

// suface icon
SDL_Surface *highscore_icon0=IMG_Load("sprites img/GUI img/highscore button0.png");
SDL_Surface *highscore_icon1=IMG_Load("sprites img/GUI img/highscore button1.png");
SDL_Surface *return_icon0=IMG_Load("sprites img/GUI img/return button0.png");
SDL_Surface *return_icon1=IMG_Load("sprites img/GUI img/return button1.png");
SDL_Surface *sound_icon0=IMG_Load("sprites img/GUI img/sound icon0.png");
SDL_Surface *sound_icon1=IMG_Load("sprites img/GUI img/sound icon1.png");
SDL_Surface *i_icon0=IMG_Load("sprites img/GUI img/i button0.png");
SDL_Surface *i_icon1=IMG_Load("sprites img/GUI img/i button1.png");
SDL_Surface *ok_button0=IMG_Load("sprites img/GUI img/ok button.png");
SDL_Surface *home_button0=IMG_Load("sprites img/GUI img/home button1.png");
SDL_Surface *home_button1=IMG_Load("sprites img/GUI img/home button2.png");
SDL_Surface *thanh_highscore=IMG_Load("sprites img/GUI img/highscore_thanh.png");


vector<SDL_Surface*> gate={gate_open,gate_close};
vector<SDL_Surface*> highscore_icon={highscore_icon0,highscore_icon1};
vector<SDL_Surface*> return_icon={return_icon0,return_icon1};
vector<SDL_Surface*> sound_icon={sound_icon0,sound_icon1};
vector<SDL_Surface*> i_icon={i_icon0,i_icon1};
vector<SDL_Surface*> home_button={home_button0,home_button1};

// extra suface
SDL_Surface *tree =IMG_Load("sprites img/extra img/Tree 01.png");
SDL_Surface *graveyard =IMG_Load("sprites img/extra img/Graveyard.png");
SDL_Surface *well =IMG_Load("sprites img/extra img/Well.png");
SDL_Surface *castle =IMG_Load("sprites img/tower img/tower/Castle.png");
SDL_Surface *villager_house_front =IMG_Load("sprites img/tower img/tower/Villager House Front.png");
SDL_Surface *view_table=IMG_Load("sprites img/GUI img/view table.png");
SDL_Surface *empty_button=IMG_Load("sprites img/GUI img/sell and update.png");
vector<SDL_Surface*> extra_item={castle,villager_house_front,well,graveyard,tree};
vector<SDL_Surface*> empty_bt={view_table,empty_button,empty_button};

//highscore screen
SDL_Surface *highscore_table =IMG_Load("sprites img/GUI img/high score.png");

// instruct screen
SDL_Surface *instruct_table=IMG_Load("sprites img/GUI img/instruct_table.png");

//// GAME SCREEN
SDL_Surface * backcircle=IMG_Load("sprites img/GUI img/black circle.png");

// surface enermy
SDL_Surface * enermy1_walk0=IMG_Load("sprites img/enermy and character img/enermy1/walking/Walking_000.png");
SDL_Surface * enermy1_walk1=IMG_Load("sprites img/enermy and character img/enermy1/walking/Walking_002.png");
SDL_Surface * enermy1_walk2=IMG_Load("sprites img/enermy and character img/enermy1/walking/Walking_003.png");
SDL_Surface * enermy1_walk3=IMG_Load("sprites img/enermy and character img/enermy1/walking/Walking_004.png");
SDL_Surface * enermy1_walk4=IMG_Load("sprites img/enermy and character img/enermy1/walking/Walking_005.png");
SDL_Surface * enermy1_walk5=IMG_Load("sprites img/enermy and character img/enermy1/walking/Walking_006.png");
SDL_Surface * enermy1_walk6=IMG_Load("sprites img/enermy and character img/enermy1/walking/Walking_007.png");
SDL_Surface * enermy1_walk7=IMG_Load("sprites img/enermy and character img/enermy1/walking/Walking_008.png");
SDL_Surface * enermy1_walk8=IMG_Load("sprites img/enermy and character img/enermy1/walking/Walking_009.png");
SDL_Surface * enermy1_walk9=IMG_Load("sprites img/enermy and character img/enermy1/walking/Walking_010.png");
SDL_Surface * enermy1_walk10=IMG_Load("sprites img/enermy and character img/enermy1/walking/Walking_011.png");
SDL_Surface * enermy1_walk11=IMG_Load("sprites img/enermy and character img/enermy1/walking/Walking_012.png");
SDL_Surface * enermy1_walk12=IMG_Load("sprites img/enermy and character img/enermy1/walking/Walking_013.png");
SDL_Surface * enermy1_walk13=IMG_Load("sprites img/enermy and character img/enermy1/walking/Walking_014.png");
SDL_Surface * enermy1_walk14=IMG_Load("sprites img/enermy and character img/enermy1/walking/Walking_015.png");
SDL_Surface * enermy1_walk15=IMG_Load("sprites img/enermy and character img/enermy1/walking/Walking_016.png");
SDL_Surface * enermy1_walk16=IMG_Load("sprites img/enermy and character img/enermy1/walking/Walking_017.png");

SDL_Surface * enermy1_dying0=IMG_Load("sprites img/enermy and character img/enermy1/dying/Dying_000.png");
SDL_Surface * enermy1_dying1=IMG_Load("sprites img/enermy and character img/enermy1/dying/Dying_002.png");
SDL_Surface * enermy1_dying2=IMG_Load("sprites img/enermy and character img/enermy1/dying/Dying_003.png");
SDL_Surface * enermy1_dying3=IMG_Load("sprites img/enermy and character img/enermy1/dying/Dying_004.png");
SDL_Surface * enermy1_dying4=IMG_Load("sprites img/enermy and character img/enermy1/dying/Dying_005.png");
SDL_Surface * enermy1_dying5=IMG_Load("sprites img/enermy and character img/enermy1/dying/Dying_006.png");
SDL_Surface * enermy1_dying6=IMG_Load("sprites img/enermy and character img/enermy1/dying/Dying_007.png");
SDL_Surface * enermy1_dying7=IMG_Load("sprites img/enermy and character img/enermy1/dying/Dying_008.png");
SDL_Surface * enermy1_dying8=IMG_Load("sprites img/enermy and character img/enermy1/dying/Dying_009.png");
SDL_Surface * enermy1_dying9=IMG_Load("sprites img/enermy and character img/enermy1/dying/Dying_010.png");
SDL_Surface * enermy1_dying10=IMG_Load("sprites img/enermy and character img/enermy1/dying/Dying_011.png");


vector<SDL_Surface*> enermy1_walk={enermy1_walk0,enermy1_walk1,enermy1_walk2,enermy1_walk3,enermy1_walk4,enermy1_walk5,
enermy1_walk6,enermy1_walk7,enermy1_walk8,enermy1_walk9,enermy1_walk10,enermy1_walk11,enermy1_walk12,enermy1_walk13,
enermy1_walk14,enermy1_walk15,enermy1_walk16};

vector<SDL_Surface*> enermy1_die={enermy1_dying0,enermy1_dying1,enermy1_dying2,enermy1_dying3,enermy1_dying4,enermy1_dying5,
enermy1_dying6,enermy1_dying7,enermy1_dying8,enermy1_dying9,enermy1_dying10};

SDL_Surface * enermy2_walk0=IMG_Load("sprites img/enermy and character img/enermy2/walking/Walking_000.png");
SDL_Surface * enermy2_walk1=IMG_Load("sprites img/enermy and character img/enermy2/walking/Walking_002.png");
SDL_Surface * enermy2_walk2=IMG_Load("sprites img/enermy and character img/enermy2/walking/Walking_003.png");
SDL_Surface * enermy2_walk3=IMG_Load("sprites img/enermy and character img/enermy2/walking/Walking_004.png");
SDL_Surface * enermy2_walk4=IMG_Load("sprites img/enermy and character img/enermy2/walking/Walking_005.png");
SDL_Surface * enermy2_walk5=IMG_Load("sprites img/enermy and character img/enermy2/walking/Walking_006.png");
SDL_Surface * enermy2_walk6=IMG_Load("sprites img/enermy and character img/enermy2/walking/Walking_007.png");
SDL_Surface * enermy2_walk7=IMG_Load("sprites img/enermy and character img/enermy2/walking/Walking_008.png");
SDL_Surface * enermy2_walk8=IMG_Load("sprites img/enermy and character img/enermy2/walking/Walking_009.png");
SDL_Surface * enermy2_walk9=IMG_Load("sprites img/enermy and character img/enermy2/walking/Walking_010.png");
SDL_Surface * enermy2_walk10=IMG_Load("sprites img/enermy and character img/enermy2/walking/Walking_011.png");
SDL_Surface * enermy2_walk11=IMG_Load("sprites img/enermy and character img/enermy2/walking/Walking_012.png");
SDL_Surface * enermy2_walk12=IMG_Load("sprites img/enermy and character img/enermy2/walking/Walking_013.png");
SDL_Surface * enermy2_walk13=IMG_Load("sprites img/enermy and character img/enermy2/walking/Walking_014.png");
SDL_Surface * enermy2_walk14=IMG_Load("sprites img/enermy and character img/enermy2/walking/Walking_015.png");
SDL_Surface * enermy2_walk15=IMG_Load("sprites img/enermy and character img/enermy2/walking/Walking_016.png");
SDL_Surface * enermy2_walk16=IMG_Load("sprites img/enermy and character img/enermy2/walking/Walking_017.png");

SDL_Surface * enermy2_dying0=IMG_Load("sprites img/enermy and character img/enermy2/dying/Dying_000.png");
SDL_Surface * enermy2_dying1=IMG_Load("sprites img/enermy and character img/enermy2/dying/Dying_002.png");
SDL_Surface * enermy2_dying2=IMG_Load("sprites img/enermy and character img/enermy2/dying/Dying_003.png");
SDL_Surface * enermy2_dying3=IMG_Load("sprites img/enermy and character img/enermy2/dying/Dying_004.png");
SDL_Surface * enermy2_dying4=IMG_Load("sprites img/enermy and character img/enermy2/dying/Dying_005.png");
SDL_Surface * enermy2_dying5=IMG_Load("sprites img/enermy and character img/enermy2/dying/Dying_006.png");
SDL_Surface * enermy2_dying6=IMG_Load("sprites img/enermy and character img/enermy2/dying/Dying_007.png");
SDL_Surface * enermy2_dying7=IMG_Load("sprites img/enermy and character img/enermy2/dying/Dying_008.png");
SDL_Surface * enermy2_dying8=IMG_Load("sprites img/enermy and character img/enermy2/dying/Dying_009.png");
SDL_Surface * enermy2_dying9=IMG_Load("sprites img/enermy and character img/enermy2/dying/Dying_010.png");
SDL_Surface * enermy2_dying10=IMG_Load("sprites img/enermy and character img/enermy2/dying/Dying_011.png");

vector<SDL_Surface*> enermy2_walk={enermy2_walk0,enermy2_walk1,enermy2_walk2,enermy2_walk3,enermy2_walk4,enermy2_walk5,
enermy2_walk6,enermy2_walk7,enermy2_walk8,enermy2_walk9,enermy2_walk10,enermy2_walk11,enermy2_walk12,enermy2_walk13,
enermy2_walk14,enermy2_walk15,enermy2_walk16};

vector<SDL_Surface*> enermy2_die={enermy2_dying0,enermy2_dying1,enermy2_dying2,enermy2_dying3,enermy2_dying4,enermy2_dying5,
enermy2_dying6,enermy2_dying7,enermy2_dying8,enermy2_dying9,enermy2_dying10};

SDL_Surface * enermy3_walk0=IMG_Load("sprites img/enermy and character img/enermy3/walking/Walking_000.png");
SDL_Surface * enermy3_walk1=IMG_Load("sprites img/enermy and character img/enermy3/walking/Walking_002.png");
SDL_Surface * enermy3_walk2=IMG_Load("sprites img/enermy and character img/enermy3/walking/Walking_003.png");
SDL_Surface * enermy3_walk3=IMG_Load("sprites img/enermy and character img/enermy3/walking/Walking_004.png");
SDL_Surface * enermy3_walk4=IMG_Load("sprites img/enermy and character img/enermy3/walking/Walking_005.png");
SDL_Surface * enermy3_walk5=IMG_Load("sprites img/enermy and character img/enermy3/walking/Walking_006.png");
SDL_Surface * enermy3_walk6=IMG_Load("sprites img/enermy and character img/enermy3/walking/Walking_007.png");
SDL_Surface * enermy3_walk7=IMG_Load("sprites img/enermy and character img/enermy3/walking/Walking_008.png");
SDL_Surface * enermy3_walk8=IMG_Load("sprites img/enermy and character img/enermy3/walking/Walking_009.png");
SDL_Surface * enermy3_walk9=IMG_Load("sprites img/enermy and character img/enermy3/walking/Walking_010.png");
SDL_Surface * enermy3_walk10=IMG_Load("sprites img/enermy and character img/enermy3/walking/Walking_011.png");
SDL_Surface * enermy3_walk11=IMG_Load("sprites img/enermy and character img/enermy3/walking/Walking_012.png");
SDL_Surface * enermy3_walk12=IMG_Load("sprites img/enermy and character img/enermy3/walking/Walking_013.png");
SDL_Surface * enermy3_walk13=IMG_Load("sprites img/enermy and character img/enermy3/walking/Walking_014.png");
SDL_Surface * enermy3_walk14=IMG_Load("sprites img/enermy and character img/enermy3/walking/Walking_015.png");
SDL_Surface * enermy3_walk15=IMG_Load("sprites img/enermy and character img/enermy3/walking/Walking_016.png");
SDL_Surface * enermy3_walk16=IMG_Load("sprites img/enermy and character img/enermy3/walking/Walking_017.png");  

SDL_Surface * enermy3_dying0=IMG_Load("sprites img/enermy and character img/enermy3/dying/Dying_000.png");
SDL_Surface * enermy3_dying1=IMG_Load("sprites img/enermy and character img/enermy3/dying/Dying_002.png");
SDL_Surface * enermy3_dying2=IMG_Load("sprites img/enermy and character img/enermy3/dying/Dying_003.png");
SDL_Surface * enermy3_dying3=IMG_Load("sprites img/enermy and character img/enermy3/dying/Dying_004.png");
SDL_Surface * enermy3_dying4=IMG_Load("sprites img/enermy and character img/enermy3/dying/Dying_005.png");
SDL_Surface * enermy3_dying5=IMG_Load("sprites img/enermy and character img/enermy3/dying/Dying_006.png");
SDL_Surface * enermy3_dying6=IMG_Load("sprites img/enermy and character img/enermy3/dying/Dying_007.png");
SDL_Surface * enermy3_dying7=IMG_Load("sprites img/enermy and character img/enermy3/dying/Dying_008.png");
SDL_Surface * enermy3_dying8=IMG_Load("sprites img/enermy and character img/enermy3/dying/Dying_009.png");
SDL_Surface * enermy3_dying9=IMG_Load("sprites img/enermy and character img/enermy3/dying/Dying_010.png");
SDL_Surface * enermy3_dying10=IMG_Load("sprites img/enermy and character img/enermy3/dying/Dying_011.png");

vector<SDL_Surface*> enermy3_walk={enermy3_walk0,enermy3_walk1,enermy3_walk2,enermy3_walk3,enermy3_walk4,enermy3_walk5,
enermy3_walk6,enermy3_walk7,enermy3_walk8,enermy3_walk9,enermy3_walk10,enermy3_walk11,enermy3_walk12,enermy3_walk13,
enermy3_walk14,enermy3_walk15,enermy3_walk16};

vector<SDL_Surface*> enermy3_die={enermy3_dying0,enermy3_dying1,enermy3_dying2,enermy3_dying3,enermy3_dying4,enermy3_dying5,
enermy3_dying6,enermy3_dying7,enermy3_dying8,enermy3_dying9,enermy3_dying10};


// surface access
SDL_Surface *arrowred10=IMG_Load("sprites img/tower img/projectiles/arrow/1/1_0.png");
SDL_Surface *arrowred11=IMG_Load("sprites img/tower img/projectiles/arrow/1/1_1.png");
SDL_Surface *arrowred12=IMG_Load("sprites img/tower img/projectiles/arrow/1/1_2.png");
SDL_Surface *arrowred13=IMG_Load("sprites img/tower img/projectiles/arrow/1/1_3.png");
SDL_Surface *arrowred14=IMG_Load("sprites img/tower img/projectiles/arrow/1/1_4.png");

SDL_Surface *arrowred20=IMG_Load("sprites img/tower img/projectiles/arrow/2/1_0.png");
SDL_Surface *arrowred21=IMG_Load("sprites img/tower img/projectiles/arrow/2/1_1.png");
SDL_Surface *arrowred22=IMG_Load("sprites img/tower img/projectiles/arrow/2/1_2.png");
SDL_Surface *arrowred23=IMG_Load("sprites img/tower img/projectiles/arrow/2/1_3.png");
SDL_Surface *arrowred24=IMG_Load("sprites img/tower img/projectiles/arrow/2/1_4.png");

SDL_Surface *arrowred30=IMG_Load("sprites img/tower img/projectiles/arrow/3/1_0.png");
SDL_Surface *arrowred31=IMG_Load("sprites img/tower img/projectiles/arrow/3/1_1.png");
SDL_Surface *arrowred32=IMG_Load("sprites img/tower img/projectiles/arrow/3/1_2.png");
SDL_Surface *arrowred33=IMG_Load("sprites img/tower img/projectiles/arrow/3/1_3.png");
SDL_Surface *arrowred34=IMG_Load("sprites img/tower img/projectiles/arrow/3/1_4.png");

vector<SDL_Surface*> arrowred1={arrowred10,arrowred11,arrowred12,arrowred13,arrowred14};
vector<SDL_Surface*> arrowred2={arrowred20,arrowred21,arrowred22,arrowred23,arrowred24};
vector<SDL_Surface*> arrowred3={arrowred30,arrowred31,arrowred32,arrowred33,arrowred34};

SDL_Surface *fireballed10=IMG_Load("sprites img/tower img/projectiles/fire ball/1/1_0.png");
SDL_Surface *fireballed11=IMG_Load("sprites img/tower img/projectiles/fire ball/1/1_1.png");
SDL_Surface *fireballed12=IMG_Load("sprites img/tower img/projectiles/fire ball/1/1_2.png");
SDL_Surface *fireballed13=IMG_Load("sprites img/tower img/projectiles/fire ball/1/1_3.png");
SDL_Surface *fireballed14=IMG_Load("sprites img/tower img/projectiles/fire ball/1/1_4.png");
SDL_Surface *fireballed15=IMG_Load("sprites img/tower img/projectiles/fire ball/1/1_5.png");
SDL_Surface *fireballed16=IMG_Load("sprites img/tower img/projectiles/fire ball/1/1_6.png");
SDL_Surface *fireballed17=IMG_Load("sprites img/tower img/projectiles/fire ball/1/1_7.png");
SDL_Surface *fireballed18=IMG_Load("sprites img/tower img/projectiles/fire ball/1/1_8.png");
SDL_Surface *fireballed19=IMG_Load("sprites img/tower img/projectiles/fire ball/1/1_9.png");
SDL_Surface *fireballed110=IMG_Load("sprites img/tower img/projectiles/fire ball/1/1_10.png");

SDL_Surface *fireballed20=IMG_Load("sprites img/tower img/projectiles/fire ball/2/1_0.png");
SDL_Surface *fireballed21=IMG_Load("sprites img/tower img/projectiles/fire ball/2/1_1.png");
SDL_Surface *fireballed22=IMG_Load("sprites img/tower img/projectiles/fire ball/2/1_2.png");
SDL_Surface *fireballed23=IMG_Load("sprites img/tower img/projectiles/fire ball/2/1_3.png");
SDL_Surface *fireballed24=IMG_Load("sprites img/tower img/projectiles/fire ball/2/1_4.png");
SDL_Surface *fireballed25=IMG_Load("sprites img/tower img/projectiles/fire ball/2/1_5.png");
SDL_Surface *fireballed26=IMG_Load("sprites img/tower img/projectiles/fire ball/2/1_6.png");
SDL_Surface *fireballed27=IMG_Load("sprites img/tower img/projectiles/fire ball/2/1_7.png");
SDL_Surface *fireballed28=IMG_Load("sprites img/tower img/projectiles/fire ball/2/1_8.png");
SDL_Surface *fireballed29=IMG_Load("sprites img/tower img/projectiles/fire ball/2/1_9.png");
SDL_Surface *fireballed210=IMG_Load("sprites img/tower img/projectiles/fire ball/2/1_10.png");

SDL_Surface *fireballed30=IMG_Load("sprites img/tower img/projectiles/fire ball/3/1_0.png");
SDL_Surface *fireballed31=IMG_Load("sprites img/tower img/projectiles/fire ball/3/1_1.png");
SDL_Surface *fireballed32=IMG_Load("sprites img/tower img/projectiles/fire ball/3/1_2.png");
SDL_Surface *fireballed33=IMG_Load("sprites img/tower img/projectiles/fire ball/3/1_3.png");
SDL_Surface *fireballed34=IMG_Load("sprites img/tower img/projectiles/fire ball/3/1_4.png");
SDL_Surface *fireballed35=IMG_Load("sprites img/tower img/projectiles/fire ball/3/1_5.png");
SDL_Surface *fireballed36=IMG_Load("sprites img/tower img/projectiles/fire ball/3/1_6.png");
SDL_Surface *fireballed37=IMG_Load("sprites img/tower img/projectiles/fire ball/3/1_7.png");
SDL_Surface *fireballed38=IMG_Load("sprites img/tower img/projectiles/fire ball/3/1_8.png");
SDL_Surface *fireballed39=IMG_Load("sprites img/tower img/projectiles/fire ball/3/1_9.png");
SDL_Surface *fireballed310=IMG_Load("sprites img/tower img/projectiles/fire ball/3/1_10.png");

vector<SDL_Surface*> fireballed1={fireballed10,fireballed11,fireballed12,fireballed13,fireballed14,fireballed15,
fireballed16,fireballed17,fireballed18,fireballed19,fireballed110};
vector<SDL_Surface*> fireballed2={fireballed20,fireballed21,fireballed22,fireballed23,fireballed24,fireballed25,
fireballed26,fireballed27,fireballed28,fireballed29,fireballed210};
vector<SDL_Surface*> fireballed3={fireballed30,fireballed31,fireballed32,fireballed33,fireballed34,fireballed35,
fireballed36,fireballed37,fireballed38,fireballed39,fireballed310};

SDL_Surface *rock=IMG_Load("sprites img/tower img/projectiles/rock/Rock.png");


// surface ground
SDL_Surface *grass_ground=IMG_Load("sprites img/ground tiles img/GrassGround.png"); 
SDL_Surface *build_ground=IMG_Load("sprites img/ground tiles img/BuildGround.png"); //o
SDL_Surface *rightup_ground=IMG_Load("sprites img/ground tiles img/DLGround.png"); // _|
SDL_Surface *downright_ground=IMG_Load("sprites img/ground tiles img/DRGround.png"); // |_
SDL_Surface *horizontal_ground=IMG_Load("sprites img/ground tiles img/HGround.png"); // -
SDL_Surface *vertical_ground=IMG_Load("sprites img/ground tiles img/VGround.png"); // |
SDL_Surface *rightdown_ground=IMG_Load("sprites img/ground tiles img/ULGround.png"); // -|
SDL_Surface *upright_ground=IMG_Load("sprites img/ground tiles img/URGround.png"); // |-
vector<SDL_Surface*> ground={grass_ground,build_ground,upright_ground,rightdown_ground,rightup_ground,downright_ground,horizontal_ground,vertical_ground};

// surface tower
SDL_Surface* archer_front=IMG_Load("sprites img/tower img/tower/Archer Tower Front.png");
SDL_Surface* archer_back=IMG_Load("sprites img/tower img/tower/Archer Tower Back.png");
SDL_Surface* castle_front=IMG_Load("sprites img/tower img/tower/Castle Tower Front.png");
SDL_Surface* castle_back=IMG_Load("sprites img/tower img/tower/Castle Tower Back.png");
SDL_Surface* knight_front=IMG_Load("sprites img/tower img/tower/Knight Post Front.png");
SDL_Surface* knight_back=IMG_Load("sprites img/tower img/tower/Knight Post Back.png");
SDL_Surface* archer_view=IMG_Load("sprites img/GUI img/arrow tower.png");
SDL_Surface* castle_view=IMG_Load("sprites img/GUI img/file ball tower.png");
SDL_Surface* knight_view=IMG_Load("sprites img/GUI img/rocks tower.png");

vector<SDL_Surface*> archer={archer_front,archer_back,archer_view};
vector<SDL_Surface*> castle_t={castle_front,castle_back,castle_view};
vector<SDL_Surface*> knight={knight_front,knight_back,knight_view};

// surface value
SDL_Surface * thanh_hienth=IMG_Load("sprites img/GUI img/value_table.png");
SDL_Surface * diamonds=IMG_Load("sprites img/GUI img/diamond.png");
SDL_Surface * waves=IMG_Load("sprites img/GUI img/wave.png");
SDL_Surface * skuds=IMG_Load("sprites img/GUI img/bone.png");
SDL_Surface * moneys=IMG_Load("sprites img/GUI img/money.png");
SDL_Surface * table_co_temp=IMG_Load("sprites img/GUI img/table with templete.png");
SDL_Surface * thanh_nhon=IMG_Load("sprites img/GUI img/thanh nhon.png");

vector<SDL_Surface*> congcu={thanh_hienth,diamonds,waves,skuds,moneys,thanh_nhon};

// surface gameover
SDL_Surface * text_over=IMG_Load("sprites img/GUI img/gameover.png");
SDL_Surface * table_over=IMG_Load("sprites img/GUI img/gameover_table.png");
SDL_Surface * sword_over=IMG_Load("sprites img/GUI img/asset_gameover1.png");
SDL_Surface * silk_over=IMG_Load("sprites img/GUI img/asset_gameover2.png");
vector<SDL_Surface *> over={text_over,table_over,sword_over,silk_over,diamonds,moneys,background_entering,ok_button0};

// surface arua
SDL_Surface *yellow_arua=IMG_Load("sprites img/GUI img/vibe up 2.png");
SDL_Surface *blue_arua=IMG_Load("sprites img/GUI img/vibe up 3.png");


// extra item
vector<vector<int>> extra1= {{1150,0},{650,150},{600,200},{110,5},{110,55},{210,5},{210,55},\
{30,220},{70,350},{0,500},{1320,250},{1200,330},{1300,400},{1190,520},{400,140},{449,290},{810,360},\
{130,620},{320,620},{500,630},{750,630},{1020,620},{1280,620},\
{0,720},{200,720},{440,710},{600,720},{800,700},{970,710},{1170,710},{1250,700}};

vector<vector<int>> extra2= {{1150,0},{680,150},{630,200},{10,155},{60,155},{10,255},{60,255},\
{30,350},{130,400},{0,500},{200,520},{1320,250},{1200,330},{1300,400},{1190,520},{570,300},{840,330},{880,150},{520,120},\
{130,620},{320,620},{500,630},{750,630},{1020,620},{1280,620},\
{0,720},{200,720},{440,710},{600,720},{800,700},{970,710},{1170,710},{1250,700}};

vector<vector<int>> extra3= {{1150,0},{520,100},{470,150},{160,5},{160,55},{260,5},{260,55},{10,405},{60,405},{10,505},{60,505},\
{130,620},{320,620},{500,630},{750,630},{1020,620},{1280,620},\
{0,720},{200,720},{440,710},{600,720},{800,700},{970,710},{1170,710},{1250,700}};

// start screen value
int length_loading=0, index_x_warning=-800, change_x_warning=30;

// value in game
int gold_ez=10, gold_medium=10 , gold_hard=20; 
int kill_1=5, kill_2=10, kill3=20;
int total_ez=40,total_med=30,total_hard=20;
int score_1=10,score_2=50,score_3=100;
int cut_vibex=1,cut_vibey=1;

// screen mode
bool start_window =true, enter_name_window=false,home_window=false,sound_window=true,highscore_window=false,instruct_window=false;
bool easy_window=false, medium_window=false,hard_window=false;
bool gameover=false,show_score=false,vibe_mode=false;

string your_name="",kieu_tower="";

int load_home=1400 , gate_mode0=0,gate_mode1=0,gate_mode2=0,return_icon_mode=0,highscore_icon_mode=0,sound_icon_mode=0,i_icon_mode=0;
int home_icon_mode=0;
int clear=2,clear_x=700,clear_y=400,clear_l=0,clear_s=0;

int back_y_in_option=1300, table_highscore_y=-850, back_y_in_high_score=-375,top1_y=-675,topy=-663;

// value of tower
bool trangthai_tower=false,show_trangthai=false;
bool arch_mode=false,cast_mode=false,knt_mode=false;
bool crafting=false,show_craft=false;