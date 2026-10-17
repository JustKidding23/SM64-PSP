# Contributing to SM64 PSP

Thanks for wanting to help. You don't need to be a programmer: playing the game on your PSP
and reporting what goes wrong helps just as much.

## Reporting a problem

[Open an issue](https://github.com/JustKidding23/SM64-PSP/issues/new/choose) and pick
"Something's wrong". It asks for your PSP model and firmware, how you got the game, and what
happened. A photo of the screen helps a lot. Please never attach a ROM, a built game or
anything taken from the game.

For an idea or an improvement, pick "Idea or improvement" instead.

## What would help

- **Testing** on other PSP models (1000, 2000, Go, Street) and other custom firmware.
- **Graphics or sound that differ from the N64 version**, with a screenshot and where in the
  game it happens.
- **Speed**, in the places where the game slows down.

## Changing the code

1. Fork the repository and make a branch from `master`.
2. Make your change, and test it (see below).
3. Open a pull request into `master` that says what it changes, why, and how you tested
   it.

The owner of this repository reviews each pull request and tries it on a PSP when possible,
so it can take a little while.

### Building

You need Linux (or WSL), the [pspdev](https://github.com/pspdev/pspdev) toolchain and your
US ROM as `baserom.us.z64`. [PSP_BUILD.md](PSP_BUILD.md) has the steps.

### Testing

- **On a PSP.** Please try your change on a real PSP if you can, and say in the pull request
  what you tested. PPSSPP is a good first check, but it doesn't behave exactly like a PSP:
  in this port, saving worked in PPSSPP but not on a PSP until it was changed.
  [PSPLink](https://github.com/pspdev/psplinkusb) can start a build over USB and show crash
  details.

## Ground rules

- **No game files.** Don't commit or attach ROMs, built games (`EBOOT.PBP`), saves, or
  graphics, sound or text taken from the game.
- **Say how you tested it.** "Played to the first gym on a PSP 3001" is perfect. "Only built
  it" is fine too, as long as it says so.
- **Keep changes focused.** One fix or feature per pull request is much easier to review.

### Using AI

This project was made with Claude, Anthropic's AI assistant, and it says so openly. Changes
made with AI tools are welcome on the same terms: say in the pull request that you used one
(and which), and make sure you've read and tested what it wrote. You're responsible for your
pull request either way.

## Upstream

Fixes to the decompilation itself belong in [n64decomp/sm64](https://github.com/n64decomp/sm64),
so that everyone gets them.
