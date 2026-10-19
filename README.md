# Cooking Mama decompilation (USA)

<!-- bytematch:start -->
[![Code](https://bytematch.dev/liolu/cooking-mama-decomp.svg?label=Code&measure=matched_code_percent)](https://bytematch.dev/liolu/cooking-mama-decomp) [![Data](https://bytematch.dev/liolu/cooking-mama-decomp.svg?label=Data&measure=matched_data_percent)](https://bytematch.dev/liolu/cooking-mama-decomp) [![Functions](https://bytematch.dev/liolu/cooking-mama-decomp.svg?label=Functions&measure=matched_functions)](https://bytematch.dev/liolu/cooking-mama-decomp)
<!-- bytematch:end -->

Nintendo DS, game code `ACCE`. Matching decompilation with Metrowerks mwccarm (compiler version still to be identified: `python tools/probe_compiler.py`).

No game assets in this repository: see `extract/README.md`.

## Progress

<!-- progress:start -->
`███░░░░░░░░░░░░░░░░░` **15.34%** of the code matched · data 0.00% · 1034/2552 functions

| Part of the code | Files | Functions | Share of all code |
|---|---|---|---|
| Auto-matched (raw m2c output, to clean up) | 1034 | 1034/1034 | 15.34% |

*Updated 2026-10-20 by `python tools/match.py progress` ([DS Decomp Studio](https://github.com/liolu/ds-decomp-studio)). A function counts only when it compiles to the exact same bytes and the ROM still rebuilds byte for byte.*
<!-- progress:end -->

```shell
python tools/configure.py usa
ninja
python tools/match.py status
```

Created from the rayman-rr template. See `AGENTS.md` for the rules.
