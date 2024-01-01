{ pkgs ? import <nixpkgs> {}}:

pkgs.mkShell {
  packages = [ pkgs.hello
    pkgs.dfu-util
    pkgs.dfu-programmer
    pkgs.avrdude
    pkgs.arduino-cli
    pkgs.gcc

  ];

}
