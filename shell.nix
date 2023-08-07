{ pkgs ? import <nixpkgs> {} }:
  pkgs.mkShell {
    nativeBuildInputs = with pkgs; [
      stdenv
      gettext
      gnumake
      pkg-config
      xorg.libX11.dev
      xorg.libXft.dev
      xorg.libXinerama.dev
      xorg.libXext.dev
      xorg.libXrender.dev
      xorg.xorgproto
      xorg.libXcursor.dev
      xorg.libxcb.dev
      xorg.libXrandr.dev
      xorg.xtrans
      glibc.dev
      fontconfig.dev
      freetype.dev
    ];
}
