/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>
/* appearance */
static const unsigned int borderpx       = 2;   /* border pixel of windows */
static const unsigned int snap           = 16;  /* snap pixel */
static const int swallowfloating         = 0;   /* 1 means swallow floating windows by default */
static const unsigned int gappih         = 8;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 8;  /* vert inner gap between windows */
static const unsigned int gappoh         = 4;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 4;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 0;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 0;   /* 0 means bottom bar */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = 'A';
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */


/* alt-tab configuration */
static const unsigned int tabmodkey        = 0x40; /* (Alt) when this key is held down the alt-tab functionality stays active. Must be the same modifier as used to run alttabstart */
static const unsigned int tabcyclekey      = 0x17; /* (Tab) when this key is hit the menu moves one position forward in client stack. Must be the same key as used to run alttabstart */
static const unsigned int tabposy          = 1;    /* tab position on Y axis, 0 = top, 1 = center, 2 = bottom */
static const unsigned int tabposx          = 1;    /* tab position on X axis, 0 = left, 1 = center, 2 = right */
static const unsigned int maxwtab          = 450;  /* tab menu width */
static const unsigned int maxhtab          = 150;  /* tab menu height */

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static const int quit_empty_window_count = 0;   /* only allow dwm to quit if no (<= count) windows are open */
static const char font[]                 = "ShureTechMono Nerd Font 11";
static const char dmenufont[]            = "ShureTechMono Nerd Font:size=11";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#222222";
static char normfloatcolor[]             = "#222222";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#6aa6e6";
static char selbordercolor[]             = "#6aa6e6";
static char selfloatcolor[]              = "#6aa6e6";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#ffffff";
static char titleselbgcolor[]            = "#6aa6e6";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#ffffff";
static char tagsselbgcolor[]             = "#6aa6e6";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";




static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};



static const char *const autostart[] = {
	"/usr/local/bin/dwmblocks", NULL,
    "xrdb", "-load", "/home/john/.Xresources", NULL,
    "dbus-update-activation-environment", "DISPLAY", "XAUTHORITY", NULL,
    "/usr/bin/gnome-keyring-daemon", "--start", "--components","=ssh,secrets,pkcs11", NULL,
    "/usr/libexec/polkit-gnome-authentication-agent-1", NULL,
    //"setxkbmap", "-model", "pc105", "-layout", "us,gr", "-option", "grp:alt_shift_toggle,caps:escape", NULL,
    "xset", "r", "rate", "280", "40", NULL,
    "/usr/bin/pipewire", NULL,
    "/usr/bin/pipewire-pulse", NULL,
    "xwallpaper", "--maximize", "/home/john/.config/background", NULL,
    "/home/john/.local/bin/onlogin.sh", NULL,
    "/home/john/.local/bin/low_battery", NULL,
    "/usr/bin/picom", "-b", NULL,
    NULL
};


/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] =
{
	[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};


/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Gimp", .tags = 1 << 4)
	RULE(.class = "Firefox", .tags = 1 << 7)
	RULE(.class = "Alacritty", .isterminal =1)
	RULE(.title = "Picture in picture", .isfloating = 1)
};



/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
	{  0,        0,     BAR_ALIGN_LEFT,  width_systray,            draw_systray,           click_systray,           NULL,                    "systray" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status,             draw_status,            click_statuscmd,         NULL,                    "status" },
	{ -1,        0,     BAR_ALIGN_NONE,   width_wintitle,           draw_wintitle,          click_wintitle,          NULL,                    "wintitle" },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */



static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};


/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },



/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	topbar ? NULL : "-b",
	NULL
};
static const char *termcmd[]    = { "alacritty", NULL };
static const char *filescmd[]   = { "pcmanfm", NULL };
static const char *roficmd[]    = { "/home/john/.local/bin/rofi-launcher", NULL };
static const char *lockcmd[]    = { "/home/john/.config/i3/scripts/i3exit", "lock", NULL };
static const char *volumeup[]   = { "/bin/sh", "-c", "/home/john/.local/bin/volume_control up && kill -45 $(pidof dwmblocks)", NULL };
static const char *volumedown[] = { "/bin/sh", "-c", "/home/john/.local/bin/volume_control down && kill -45 $(pidof dwmblocks)", NULL };
static const char *volumemute[] = { "/bin/sh", "-c", "/home/john/.local/bin/volume_control mute && kill -45 $(pidof dwmblocks)", NULL };
static const char *backlight[]  = { "/home/john/.local/bin/dunst_backlight", NULL };
static const char *kbdcmd[]     = { "/bin/sh", "-c", "/home/john/.local/bin/dunst_kbdlayout && kill -41 $(pidof dwmblocks)", NULL };
static const char *screenmenu[] = { "/home/john/.local/bin/rofi-screenshot", NULL };
static const char *screenfull[] = { "/home/john/.local/bin/screenshot", "fullscreen", NULL };
static const char *screenwin[]  = { "/home/john/.local/bin/screenshot", "window", NULL };
static const char *screensel[]  = { "/home/john/.local/bin/screenshot", "selection", NULL };
static const char *logoutmenu[] = { "/home/john/.local/bin/rofi-power", NULL };

/* This defines the name of the executable that handles the bar (used for signalling purposes) */
#define STATUSBAR "dwmblocks"


static const Key keys[] = {
	/* modifier                     key            function                argument */
	{ MODKEY,                       XK_p,          spawn,                  {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_d,          spawn,                  {.v = roficmd } },
	{ MODKEY|ShiftMask,             XK_Return,     spawn,                  {.v = termcmd } },
	{ MODKEY,                       XK_e,          spawn,                  {.v = filescmd } },
	{ MODKEY|ControlMask,           XK_l,          spawn,                  {.v = lockcmd } },
	{ Mod1Mask,                     XK_Shift_L,    spawn,                  {.v = kbdcmd } },
	{ 0,                            XK_Print,      spawn,                  {.v = screenfull } },
	{ ShiftMask,                    XK_Print,      spawn,                  {.v = screensel } },
	{ ControlMask,                  XK_Print,      spawn,                  {.v = screenwin } },
	{ MODKEY,                       XK_Print,      spawn,                  {.v = screenmenu } },
	{ MODKEY,                       XK_Escape,     spawn,                  {.v = logoutmenu } },
	{ 0,               XF86XK_AudioRaiseVolume,    spawn,                  {.v = volumeup } },
	{ 0,               XF86XK_AudioLowerVolume,    spawn,                  {.v = volumedown } },
	{ 0,               XF86XK_AudioMute,           spawn,                  {.v = volumemute } },
	{ 0,               XF86XK_MonBrightnessUp,     spawn,                  {.v = backlight } },
	{ 0,               XF86XK_MonBrightnessDown,   spawn,                  {.v = backlight } },
	{ MODKEY,                       XK_b,          togglebar,              {0} },
	{ MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,             {.i = -1 } },
	{ MODKEY,                       XK_i,          incnmaster,             {.i = +1 } },
	{ MODKEY,                       XK_d,          incnmaster,             {.i = -1 } },
	{ MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,          movestack,              {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,          movestack,              {.i = -1 } },
	{ MODKEY,                       XK_Return,     zoom,                   {0} },
	{ MODKEY|Mod4Mask,              0,          incrgaps,               {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    0,          incrgaps,               {.i = -1 } },
	{ MODKEY|Mod4Mask,              0,          incrigaps,              {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    0,          incrigaps,              {.i = -1 } },
	{ MODKEY|Mod4Mask,              0,          incrogaps,              {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    0,          incrogaps,              {.i = -1 } },
	{ MODKEY|Mod4Mask,              0,          incrihgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    0,          incrihgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              0,          incrivgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    0,          incrivgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              0,          incrohgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    0,          incrohgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              0,          incrovgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    0,          incrovgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask|ControlMask,  XK_g,       togglegaps,             {0} },
	{ MODKEY|Mod4Mask,              0,          defaultgaps,            {0} },
	{ Mod1Mask,                     XK_Tab,        alttabstart,            {0} },
	{ MODKEY,                       XK_q,          killclient,             {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,          quit,                   {0} },
	{ MODKEY,                       XK_u,          focusurgent,            {0} },
	{ MODKEY,                       XK_t,          setlayout,              {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,          setlayout,              {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,          setlayout,              {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,      setlayout,              {0} },
	{ MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
	{ MODKEY,                       XK_y,          togglefullscreen,       {0} },
	{ MODKEY|ShiftMask,             XK_s,          togglesticky,           {0} },
	{ MODKEY,                       XK_0,          view,                   {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~0 } },
	{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button1,        sigstatusbar,   {.i = 1 } },
	{ ClkStatusText,        0,                   Button2,        sigstatusbar,   {.i = 2 } },
	{ ClkStatusText,        0,                   Button3,        sigstatusbar,   {.i = 3 } },
	{ ClkStatusText,        0,                   Button4,        sigstatusbar,   {.i = 4 } },
	{ ClkStatusText,        0,                   Button5,        sigstatusbar,   {.i = 5 } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};


