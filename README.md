# ReverseNX
SaltyNX plugin that forces games to think that you are using docked or handheld mode.

To download latest SaltyNX, go [here](https://github.com/masagrator/SaltyNX/releases).

You can use that to change graphics settings and unlock some options that are available only in docked/handheld mode.
For now in experimental phase, because SaltyNX has many bugs that need to be patched.

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

- SaltyNX is still under development, so it may cause issues on it's own. More in SaltyNX repo.

[Confirmed games working or not](gameslist.md)

**exceptions.txt** contains titleids of games that for some reason are not compatible with SaltyNX in newest release of ReverseNX.
Put this file to SaltySD folder.

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
