# ReverseNX
SaltyNX plugin that replace games checks if you are using docked or handheld mode. They are mostly used to determine graphics settings and unlocking some options that are available only in docked/handheld mode.

For now in experimental phase, because SaltyNX has many bugs that need to be patched.

Tests were done on FW 7.0.1-8.1.0, Atmosphere 0.9.1-0.9.2

It should work with ReinX too.

SX OS is not supported.

-----------

Plugin can work globally or per titleid.

To activate loading per titleid, put empty file `titleid.flag` to `saltysd/flags/ReverseNX/`

You can use ReverseNX-Tool homebrew for easier management of both modes.

https://github.com/masagrator/ReverseNX-Tool

------------

Flags:
create in folder `saltysd/plugins/ReverseNX/` (globally) or `saltysd/plugins/(title_id)/ReverseNX/` (per titleid) empty file:
- `docked.flag` for docked mode

or

- `handheld.flag` for handheld mode 

When both flags are there or none of them, plugin will ignore loading.

For docked flag is recommended to use OC settings exactly as used in docked mode:

>handheld_charging_gpu=768
>
>handheld_charging_mem=1600

-----------

Known issues:

- SaltyNX is still under development, so it may cause issues on it's own:

> Different versions of game can behave diversely,
>
> Instability with some homebrews,
>
> Some games may crash for unknown reason in one Switch, in another it works without issues,
>
> EmuMMC freezes in newer FW version using Hekate Launch menu (from tests it works with 4.1.0/6.1.0/6.2.0), confirmed that enabling emummc and using fusee-primary (with Hekate Payload menu too) works with 7.0.1/8.1.0.
>
> 32 bit games are unsupported,
>
> Sometimes have issues with Hekate when it's not loading cfw from Payload menu.
>
> 0.3X Release crashes OS if something is blocking access to svcGetDebugEventInfo when game is booting (f.e. Atmosphere cheats if it's enabled and files are in cheats folder of booting game),
>
> For EmuMMC (and maybe sysnand too): if you use freebird, then OS can crash if you try to open hbmenu while running game (don't know if this was an issue with older releases).

[Confirmed games working or not](gameslist.md)


-----------

Thanks to 

**shinyquagsire23** for *SaltyNX*

https://github.com/shinyquagsire23/SaltyNX

**ultimate-research** for *code-mod-framework*

https://github.com/ultimate-research/code-mod-framework

**jugeeya** for precompiled SaltyNX nsp sysmodule. Originally it's compiled as kip (precompiled sysmodule only in release)
*Deprecated from 0.3 release*
https://github.com/jugeeya/UltimateTrainingModpack/releases/tag/1.1

**zakaria** and **crow132** for testing

How to compile plugin

https://github.com/ultimate-research/code-mod-framework/wiki/Environment-Setup:-Getting-Started

It still works even with warnings about not converting unsigned integers properly. Dunno how to repair it.
