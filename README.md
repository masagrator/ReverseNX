# ReverseNX
SaltyNX plugin that replace games checks if you are using docked or handheld mode. They are mostly used to determine graphics settings and unlocking some options that are available only in docked/handheld mode.

For now in experimental phase, because it looks like SaltyNX is not in good terms with some games (they will crash without any plugin)  or maybe I screwed up.

Tests were done on FW 7.0.1-8.1.0, Atmosphere 0.9.1-0.9.2

It should work with ReinX too.

SX OS is not supported.

-----------

Plugin works always globally. For now flag per titleid is not supported.

Flags:
create in folder `saltysd/plugins/ReverseNX/` empty file:
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
> EmuMMC freezes.
>
> 32 bit games are unsupported (they break SaltyNX)
>
> Sometimes have issues with Hekate when it's not loading cfw from Payload menu.

[Confirmed games working or not](gameslist.md)


-----------

Thanks to 

**shinyquagsire23** for *SaltyNX*

https://github.com/shinyquagsire23/SaltyNX

**ultimate-research** for *code-mod-framework*

https://github.com/ultimate-research/code-mod-framework

**jugeeya** for precompiled SaltyNX nsp sysmodule. Originally it's compiled as kip (precompiled sysmodule only in release)
https://github.com/jugeeya/UltimateTrainingModpack/releases/tag/1.1

**zakaria** for testing

How to compile plugin

https://github.com/ultimate-research/code-mod-framework/wiki/Environment-Setup:-Getting-Started

It still works even with errors about not converting unsigned integers properly. Dunno how to repair it.
