# dwm
A custom build of dwm using [dwm-flexipatch](https://github.com/bakkeby/dwm-flexipatch) and [flexipatch-finalizer](https://github.com/bakkeby/flexipatch-finalizer).
You can find the keybindings [here](https://github.com/imatsatsos/dwm/wiki#keybindings)
![1690027396](https://github.com/imatsatsos/dwm/assets/49369992/a38bbb19-95e6-4766-b97f-9065c29dc35c)

## Build & install
Install dependencies:  
```base-devel libX11-devel libXft-devel libXinerama-devel pango-devel fontconfig-devel freetype-devel```

Build and install:  
```make install```

### Apps
```st dmenu pcmanfm rofi picom xwallpaper i3lock dunst maim```

### Statusbar
- dwmblocks from my [custom build](https://github.com/imatsatsos/dwmblocks-async)
- Status bar script from my [dotfiles](https://github.com/imatsatsos/dotfiles/tree/main/.local/bin/status)

### Other info:
- Font: [Inter](https://github.com/rsms/inter)
- Wallpaper: [link](https://wallhaven.cc/w/exwgv8)

## Patches
- BAR_BORDER
- BAR_DWMBLOCKS
- BAR_STATUSCMD
- BAR_SYSTRAY
- BAR_DMENUMATCHTOP
- BAR_PADDING
- ALWAYSCENTER
- ATTACH_BOTTOM
- FOCUSFOLLOWMOUSE
- FOCUSONNETACTIVE
- MOVESTACK
- NOBORDER
- RESIZECORNERS
- SAVEFLOATS
- STATUS2D
- STICKY
- TOGGLEFULLSCREEN
- LOSEFULLSCREEN
- VANITYGAPS
- ZOOMSWAP
- TAB
- WINVIEW
