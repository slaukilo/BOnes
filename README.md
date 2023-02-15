# BOnes - NES Emulator

**BOnes** is a Nintendo Entertainment System Emulator written in C with the goal of using a fun project to build my skills.

BOnes is made with the goal of being cross-platform for macOS, Windows, and Linux systems.

Clean performace with minimal bugs is the long-term vision for this project while maintaining simplicity in implementation.

## Mappers

Most popular Mappers from Nintendo will be used:

 \#  | Name  | Some Games
-----|-------|--------------------------------------------------
 000 | NROM  | Super Mario Bros. 1, Donkey Kong, Duck Hunt
 001 | MMC1  | Legend of Zelda, Dr. Mario, Metroid
 002 | UxROM | Megaman, Contra, Castlevania
 003 | CNROM | Arkanoid, Cybernoid, Solomon's Key
 004 | MMC3  | Super Mario Bros 2 & 3, Kirby's Adventure
 007 | AxROM | Marble Madness, Battletoads
 009 | MMC2  | Punch Out!!

## To-Do's

### Primary Milestones

- [ ] Parse iNES files
- [ ] Create Cartridges (iNES + Mapper interface)
- [ ] CPU
  - [ ] Set Up Memory Map
  - [ ] Hardware Structures (registers)
  - [ ] Core Loop / Basic Functionality
    - [ ] Read / Write RAM
    - [ ] Addressing Modes
    - [ ] Fetch - Decode - Execute
  - [ ] Official Opcodes Implemented
  - [ ] Handle Interrupts
- [ ] PPU
  - [ ] Set Up Basic Rendering Context (SDL)
  - [ ] Implement Registers + Memory Map them
  - [ ] Implement DMA
  - [ ] Generate NMI -> CPU
  - [ ] Core rendering loop
    - [ ] Background Rendering
    - [ ] Sprite Rendering - _currently not hardware accurate_
    - [ ] Proper Background / Foreground blending
  - [ ] Sprite Zero Hit
  - [ ] Misc PPU flags (emphasize RGB, Greyscale, etc...)
- [ ] APU
  - [ ] Implement Registers + Memory Map them
  - [ ] Frame Timer IRQ
  - [ ] Set Up Basic Sound Output Context (SDL)
  - [ ] Channels
    - [ ] Pulse 1
    - [ ] Pulse 2
    - [ ] Triangle
    - [ ] Noise
    - [ ] DMC
  - [ ] DMC DMA
- [ ] Joypads
  - [ ] Basic Controller
