/*
 * Rogue definitions and variable declarations
 *
 * @(#)netprot.h	5.42 (Berkeley) 08/06/83
 */

#include "network.h"
#include <stdarg.h>

/*
 * Maximum number of different things
 */
#define MAXROOMS	9
#define MAXTHINGS	9
#define MAXOBJ		9
#define MAXPACK		23
#define MAXTRAPS	10
#define AMULETLEVEL	26
#define	NUMTHINGS	7	/* number of types of things */
#define MAXPASS		13	/* upper limit on number of passages */
#define	NUMLINES	24
#define	NUMCOLS		80
#define STATLINE		(NUMLINES - 1)
#define BORE_LEVEL	50

/*
 * return values for get functions
 */
#define	NORM	0	/* normal exit */
#define	QUIT	1	/* quit option setting */
#define	MINUS	2	/* back up one option */

/*
 * inventory types
 */
#define	INV_OVER	0
#define	INV_SLOW	1
#define	INV_CLEAR	2

/*
 * All the fun defines
 */
#define when		break;case
#define otherwise	break;default
#define until(expr)	while(!(expr))
#define next(ptr)	(*ptr).l_next
#define prev(ptr)	(*ptr).l_prev
#define winat(y,x)	(moat(y,x) != NULL ? moat(y,x)->t_disguise : chat(y,x))
#define ce(a,b)		((a).x == (b).x && (a).y == (b).y)
#define Hero		Player.t_pos
#define Pstats		Player.t_stats
#define Pack		Player.t_pack
#define Proom		Player.t_room
#define Max_hp		Player.t_stats.s_maxhp
#define attach(a,b)	_attach(&a,b)
#define detach(a,b)	_detach(&a,b)
#define free_list(a)	_free_list(&a)
#define max(a,b)	((a) > (b) ? (a) : (b))
#define on(thing,flag)	(((thing).t_flags & (flag)) != 0)
#define GOLDCALC	(rnd(50 + 10 * Level) + 2)
#define ISRING(h,r)	(Cur_ring[h] != NULL && Cur_ring[h]->o_which == r)
#define ISWEARING(r)	(ISRING(LEFT, r) || ISRING(RIGHT, r))
#define ISMULT(type) 	(type == POTION || type == SCROLL || type == FOOD)
#define INDEX(y,x)	(&Places[((x) << 5) + (y)])
#define chat(y,x)	(Places[((x) << 5) + (y)].p_ch)
#define flat(y,x)	(Places[((x) << 5) + (y)].p_flags)
#define moat(y,x)	(Places[((x) << 5) + (y)].p_monst)
#define unc(cp)		(cp).y, (cp).x
#ifdef MASTER
#define debug		if (Wizard) msg
#endif

/*
 * Things that appear on the screens
 */
#define PASSAGE		'#'
#define DOOR		'+'
#define FLOOR		'.'
#define PLAYER		'@'
#define TRAP		'^'
#define STAIRS		'%'
#define GOLD		'*'
#define POTION		'!'
#define SCROLL		'?'
#define MAGIC		'$'
#define FOOD		':'
#define WEAPON		')'
#define ARMOR		']'
#define AMULET		','
#define RING		'='
#define STICK		'/'
#define CALLABLE	-1
#define R_OR_S		-2

/*
 * Various constants
 */
#define BEARTIME	spread(3)
#define SLEEPTIME	spread(5)
#define HOLDTIME	spread(2)
#define WANDERTIME	spread(70)
#define BEFORE		spread(1)
#define AFTER		spread(2)
#define HEALTIME	30
#define HUHDURATION	20
#define SEEDURATION	850
#define HUNGERTIME	1300
#define MORETIME	150
#define STOMACHSIZE	2000
#define STARVETIME	850
#define ESCAPE		27
#define LEFT		0
#define RIGHT		1
#define BOLT_LENGTH	6
#define LAMPDIST	3
#ifdef MASTER
#define	PASSWD		"mTsdVv0Uvy4xY"
#endif

/*
 * Save against things
 */
#define VS_POISON	00
#define VS_PARALYZATION	00
#define VS_DEATH	00
#define VS_BREATH	02
#define VS_MAGIC	03

/*
 * Various flag bits
 */
/* flags for rooms */
#define ISDARK	0000001		/* room is dark */
#define ISGONE	0000002		/* room is gone (a corridor) */
#define ISMAZE	0000004		/* room is gone (a corridor) */

/* flags for objects */
#define ISCURSED 000001		/* object is cursed */
#define ISKNOW	0000002		/* player knows details about the object */
#define ISMISL	0000004		/* object is a missile type */
#define ISMANY	0000010		/* object comes in groups */
/*	ISFOUND 0000020		...is used for both objects and creatures */
#define	ISPROT	0000040		/* armor is permanently protected */

/* flags for creatures */
#define CANHUH	0000001		/* creature can confuse */
#define CANSEE	0000002		/* creature can see invisible creatures */
#define ISBLIND	0000004		/* creature is blind */
#define ISCANC	0000010		/* creature has special qualities cancelled */
#define ISLEVIT	0000010		/* hero is levitating */
#define ISFOUND	0000020		/* creature has been seen (used for objects) */
#define ISGREED	0000040		/* creature runs to protect gold */
#define ISHASTE	0000100		/* creature has been hastened */
#define ISTARGET 000200		/* creature is the target of an 'f' command */
#define ISHELD	0000400		/* creature has been held */
#define ISHUH	0001000		/* creature is confused */
#define ISINVIS	0002000		/* creature is invisible */
#define ISMEAN	0004000		/* creature can wake when player enters room */
#define ISHALU	0004000		/* hero is on acid trip */
#define ISREGEN	0010000		/* creature can regenerate */
#define ISRUN	0020000		/* creature is running at the player */
#define SEEMONST 040000		/* hero can detect unseen monsters */
#define ISFLY	0040000		/* creature can fly */
#define ISSLOW	0100000		/* creature has been slowed */

/*
 * Flags for level map
 */
#define F_PASS		0x80		/* is a passageway */
#define F_SEEN		0x40		/* have seen this spot before */
#define F_DROPPED	0x20		/* object was dropped here */
#define F_LOCKED	0x20		/* door is locked */
#define F_REAL		0x10		/* what you see is what you get */
#define F_PNUM		0x0f		/* passage number mask */
#define F_TMASK		0x07		/* trap number mask */

/*
 * Trap types
 */
#define T_DOOR	00
#define T_ARROW	01
#define T_SLEEP	02
#define T_BEAR	03
#define T_TELEP	04
#define T_DART	05
#define T_RUST	06
#define NTRAPS	7

/*
 * Potion types
 */
#define P_CONFUSE	0
#define P_LSD		1
#define P_POISON	2
#define P_STRENGTH	3
#define P_SEEINVIS	4
#define P_HEALING	5
#define P_MFIND		6
#define	P_TFIND 	7
#define	P_RAISE		8
#define P_XHEAL		9
#define P_HASTE		10
#define P_RESTORE	11
#define P_BLIND		12
#define P_LEVIT		13
#define MAXPOTIONS	14

/*
 * Scroll types
 */
#define S_CONFUSE	0
#define S_MAP		1
#define S_HOLD		2
#define S_SLEEP		3
#define S_ARMOR		4
#define S_ID_POTION	5
#define S_ID_SCROLL	6
#define S_ID_WEAPON	7
#define S_ID_ARMOR	8
#define S_ID_R_OR_S	9
#define S_SCARE		10
#define S_FDET		11
#define S_TELEP		12
#define S_ENCH		13
#define S_CREATE	14
#define S_REMOVE	15
#define S_AGGR		16
#define S_PROTECT	17
#define MAXSCROLLS	18

/*
 * Weapon types
 */
#define MACE		0
#define SWORD		1
#define BOW		2
#define ARROW		3
#define DAGGER		4
#define TWOSWORD	5
#define DART		6
#define SHIRAKEN	7
#define SPEAR		8
#define FLAME		9	/* fake entry for dragon breath (ick) */
#define MAXWEAPONS	9	/* this should equal FLAME */

/*
 * Armor types
 */
#define LEATHER		0
#define RING_MAIL	1
#define STUDDED_LEATHER	2
#define SCALE_MAIL	3
#define CHAIN_MAIL	4
#define SPLINT_MAIL	5
#define BANDED_MAIL	6
#define PLATE_MAIL	7
#define MAXARMORS	8

/*
 * Ring types
 */
#define R_PROTECT	0
#define R_ADDSTR	1
#define R_SUSTSTR	2
#define R_SEARCH	3
#define R_SEEINVIS	4
#define R_NOP		5
#define R_AGGR		6
#define R_ADDHIT	7
#define R_ADDDAM	8
#define R_REGEN		9
#define R_DIGEST	10
#define R_TELEPORT	11
#define R_STEALTH	12
#define R_SUSTARM	13
#define MAXRINGS	14

/*
 * Rod/Wand/Staff types
 */
#define WS_LIGHT	0
#define WS_INVIS	1
#define WS_ELECT	2
#define WS_FIRE		3
#define WS_COLD		4
#define WS_POLYMORPH	5
#define WS_MISSILE	6
#define WS_HASTE_M	7
#define WS_SLOW_M	8
#define WS_DRAIN	9
#define WS_NOP		10
#define WS_TELAWAY	11
#define WS_TELTO	12
#define WS_CANCEL	13
#define MAXSTICKS	14

/*
 * Now we define the structures and types
 */

/*
 * Help list
 */
struct h_list {
    char h_ch;
    char *h_desc;
    bool h_print;
};

/*
 * Coordinate data type
 */
typedef struct {
    int y;
    int x;
} coord;

typedef unsigned int str_t;

/*
 * Stuff about objects
 */
struct obj_info {
    char *oi_name;
    int oi_prob;
    short oi_worth;
    char *oi_guess;
    bool oi_know;
};

/*
 * Room structure
 */
struct room {
    coord r_pos;			/* Upper left corner */
    coord r_max;			/* Size of room */
    coord r_gold;			/* Where the gold is */
    int r_goldval;			/* How much the gold is worth */
    short r_flags;			/* Info about the room */
    int r_nexits;			/* Number of exits */
    coord r_exit[12];			/* Where the exits are */
};

/*
 * Structure describing a fighting being
 */
struct stats {
    str_t s_str;			/* Strength */
    long s_exp;				/* Experience */
    int s_lvl;				/* Level of mastery */
    int s_arm;				/* Armor class */
    short s_hpt;			/* Hit points */
    char s_dmg[13];			/* String describing damage done */
    short s_maxhp;			/* Max hit points */
};

/*
 * Structure for monsters and player
 */
union thing {
    struct {
	union thing *_l_next, *_l_prev;	/* Next pointer in link */
	coord _t_pos;			/* Position */
	bool _t_turn;			/* If slowed, is it a turn to move */
	char _t_type;			/* What it is */
	char _t_disguise;		/* What mimic looks like */
	char _t_oldch;			/* Character that was where it was */
	coord *_t_dest;			/* Where it is running to */
	short _t_flags;			/* State word */
	struct stats _t_stats;		/* Physical description */
	struct room *_t_room;		/* Current room for thing */
	union thing *_t_pack;		/* What the thing is carrying */
    } _t;
    struct {
	union thing *_l_next, *_l_prev;	/* Next pointer in link */
	int _o_type;			/* What kind of object it is */
	coord _o_pos;			/* Where it lives on the screen */
	char *_o_text;			/* What it says if you read it */
	char _o_launch;			/* What you need to launch it */
	char _o_packch;			/* What character it is in the pack */
	char *_o_damage;		/* Damage if used like sword */
	char *_o_hurldmg;		/* Damage if thrown */
	int _o_count;			/* Count for plural objects */
	int _o_which;			/* Which object of a type it is */
	int _o_hplus;			/* Plusses to hit */
	int _o_dplus;			/* Plusses to damage */
	short _o_arm;			/* Armor protection */
	short _o_flags;			/* Information about objects */
	int _o_group;			/* Group number for this object */
	char *_o_label;			/* Label for object */
    } _o;
};

typedef union thing THING;

#define l_next		_t._l_next
#define l_prev		_t._l_prev
#define t_pos		_t._t_pos
#define t_turn		_t._t_turn
#define t_type		_t._t_type
#define t_disguise	_t._t_disguise
#define t_oldch		_t._t_oldch
#define t_dest		_t._t_dest
#define t_flags		_t._t_flags
#define t_stats		_t._t_stats
#define t_pack		_t._t_pack
#define t_room		_t._t_room
#define o_type		_o._o_type
#define o_pos		_o._o_pos
#define o_text		_o._o_text
#define o_launch	_o._o_launch
#define o_packch	_o._o_packch
#define o_damage	_o._o_damage
#define o_hurldmg	_o._o_hurldmg
#define o_count		_o._o_count
#define o_which		_o._o_which
#define o_hplus		_o._o_hplus
#define o_dplus		_o._o_dplus
#define o_arm		_o._o_arm
#define o_charges	o_arm
#define o_goldval	o_arm
#define o_flags		_o._o_flags
#define o_group		_o._o_group
#define o_label		_o._o_label

/*
 * describe a place on the level map
 */
typedef struct {
    char p_ch;
    char p_flags;
    THING *p_monst;
} PLACE;

/*
 * Array containing information on all the various types of monsters
 */
struct monster {
    char *m_name;			/* What to call the monster */
    int m_carry;			/* Probability of carrying something */
    short m_flags;			/* Things about the monster */
    struct stats m_stats;		/* Initial stats */
};

/*
 * External variables
 */

extern bool	After, Again, Allscore, Amulet, Door_stop, Fight_flush,
		Firstmove, Has_hit, Inv_describe, Jump, Kamikaze,
		Lower_msg, Move_on, Msg_esc, Noscore, Pack_used[],
		Passgo, Playing, Q_comm, Running, Save_msg, See_floor,
		Seenstairs, Stat_msg, Terse, To_death, Tombstone;

extern char	Dir_ch, File_name[], Home[], Huh[], *Inv_t_name[],
		L_last_comm, L_last_dir, Last_comm, Last_dir, *Numname,
		Outbuf[], *P_colors[], *R_stones[], *Release, Runch,
		*S_names[], Take, *Tr_name[], *Ws_made[], *Ws_type[];

extern int	A_class[], Count, Food_left, Hungry_state, Inpack,
		Inv_type, Lastscore, Level, Max_hit, Max_level, Mpos,
		N_objs, No_command, No_food, No_move, Ntraps, Purse,
		Quiet, Vf_hit;

extern unsigned int	numscores;

extern long	Dnum, E_levels[], Seed;

extern WINDOW	*Hw;

extern coord	Delta, Oldpos, Stairs;

extern PLACE	Places[];

extern THING	*Cur_armor, *Cur_ring[], *Cur_weapon, *L_last_pick,
		*Last_pick, *Lvl_obj, *Mlist, Player;

extern struct h_list	Helpstr[];

extern struct room	*Oldrp, Passages[], Rooms[];

extern struct stats	Max_stats;

extern struct monster	Monsters[];

extern struct obj_info	Arm_info[], Pot_info[], Ring_info[],
			Scr_info[], Things[], Ws_info[], Weap_info[];

/*
 * Function types
 */
void	accnt_maze(int y, int x, int ny, int nx);
void	badcheck(char *name, struct obj_info *info, int bound);
void	bounce(THING *weap, char *mname, bool noend);
void	call(void);
void	check_level(void);
void	conn(int r1, int r2);
void	current(THING *cur, char *how, char *where);
void	d_level(void);
void	dig(int y, int x);
void	discard(THING *item);
void	do_chase(THING *th);
void	do_maze(struct room *rp);
void	do_motion(THING *obj, int ydelta, int xdelta);
void	do_pot(int type, bool knowit);
void	doadd(char *fmt, va_list args);
void	door(struct room *rm, coord *cp);
void	drain(void);
void	draw_room(struct room *rp);
void	encwrite(char *start, unsigned int size, FILE *outf);
void	erase_lamp(coord *pos, struct room *rp);
void	fall(THING *obj, bool pr);
void	fire_bolt(coord *start, coord *dir, char *name);
void	help(void);
void	hit(char *er, char *ee, bool noend);
void	horiz(struct room *rp, int starty);
void	identify(void);
void	illcom(char ch);
void	invis_on(void);
void	killed(THING *tp, bool pr);
void	miss(char *er, char *ee, bool noend);
void	money(int value);
void	move_monst(THING *tp);
void	move_msg(THING *obj);
void	nameit(THING *obj, char *type, char *which, struct obj_info *op, char *(*prfunc)(THING *));
void	numpass(int y, int x);
void	passnum(void);
void	pr_spec(struct obj_info *info, int nitems);
void	put_bool(void *b);
void	put_inv_t(void *ip);
void	put_str(void *str);
void	put_things(void);
void	putpass(coord *cp);
void	raise_level(void);
void	relocate(THING *th, coord *new_loc);
void	remove_mon(coord *mp, THING *tp, bool waskill);
void	reset_last(void);
void	rust_armor(THING *arm);
void	save_file(FILE *savef);
void	search(void);
void	set_know(THING *obj, struct obj_info *info);
void	set_oldch(THING *tp, coord *cp);
void	strucpy(char *s1, char *s2, int len);
void	thunk(THING *weap, char *mname, bool noend);
void	treas_room(void);
void	turnref(void);
void	u_level(void);
void	uncurse(THING *obj);
void	vert(struct room *rp, int startx);
void	wait_for(char ch);
void	waste_time(void);

bool	chase(THING *tp, coord *ee);
bool	diag_ok(coord *sp, coord *ep);
bool	dropcheck(THING *obj);
bool	fallpos(coord *pos, coord *newpos);
bool	find_floor(struct room *rp, coord *cp, int limit, bool monst);
bool	is_magic(THING *obj);
bool	levit_check(void);
bool	pack_room(bool from_floor, THING *obj);
bool	roll_em(THING *thatt, THING *thdef, THING *weap, bool hurl);
bool	see_monst(THING *mp);
bool	seen_stairs(void);
bool	turn_ok(int y, int x);
bool	turn_see(bool turn_off);

char	be_trapped(coord *tc);
char	floor_ch(void);
char	pack_char(void);

char	*charge_str(THING *obj);
char	*choose_str(char *ts, char *ns);
char	*inv_name(THING *obj, bool drop);
char	*nullstr(THING *ignored);
char	*num(int n1, int n2, char type);
char	*ring_num(THING *obj);
char	*set_mname(THING *tp);
char	*vowelstr(char *str);

int	get_bool(void *vp, WINDOW *win);
int	get_inv_t(void *vp, WINDOW *win);
int	get_num(void *vp, WINDOW *win);
int	get_sf(void *vp, WINDOW *win);
int	get_str(void *vopt, WINDOW *win);
int	trip_ch(int y, int x, char ch);

coord	*find_dest(THING *tp);
coord	*rndmove(THING *who);

THING	*find_obj(int y, int x);
THING	*get_item(char *purpose, int type);
THING	*leave_pack(THING *obj, bool newobj, bool all);
THING	*new_item(void);
THING	*new_thing(void);

struct room	*roomin(coord *cp);
