# dwm
A custom build of dwm using [dwm-flexipatch](https://github.com/bakkeby/dwm-flexipatch) and [flexipatch-finalizer](https://github.com/bakkeby/flexipatch-finalizer).

![1690027396](https://github.com/imatsatsos/dwm/assets/49369992/a38bbb19-95e6-4766-b97f-9065c29dc35c)

## Build & install
Install dependencies:
```base-devel libX11-devel libXft-devel libXinerama-devel pango-devel fontconfig-devel freetype-devel```

Build and install:
```make install```

## Requirements
### Apps
```alacritty pcmanfm rofi dmenu picom xwallpaper i3lock dunst maim```

### Statusbar
- dwmblocks from my [custom build](https://github.com/imatsatsos/dwmblocks-async)
- Status bar script from my [dotfiles](https://github.com/imatsatsos/dotfiles/tree/main/.local/bin/status)
Dependencies: ```upower alsa-utils xset```

### Misc
```polkit-gnome gnome-keyring pipewire wireplumber xrdb xclip xsetroot setxkbmap xdg-utils xrdb```

## Other info:
- Font: [Shure Tech Mono Nerd](https://github.com/ryanoasis/nerd-fonts/tree/master/patched-fonts/ShareTechMono)
- Wallpaper: [link](https://wallhaven.cc/w/exwgv8)

## Patches
- BAR_DWMBLOCKS
- BAR_STATUSCMD
- BAR_SYSTRAY
- BAR_DMENUMATCHTOP
- BAR_PANGO
- ALT_TAB
- ATTACH_BOTTOM
- COOL_AUTOSTART
- FOCUSFOLLOWMOUSE
- FOCUSURGENT
- MOVESTACK
- NOBORDER
- ONLYQUITONEMPTY
- RESIZECORNERS
- SAVEFLOATS
- STICKY
- SWALLOW
- TOGGLEFULLSCREEN
- VANITYGAPS
- ZOOMSWAP

