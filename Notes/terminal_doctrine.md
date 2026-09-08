

### Terminal / C++ workflow

First off. Don't overcomplicate things. Treat your brain like a file system. You know where stuff is and know when to use it. Take your mind off it and call a t/o if it's making you lost and remember this stuff. Just make sure know what to do in real time. Value proof over claims always. Knowledge should be trained to be actively recalled because that's the only reason you're learning it anyways. Unlearn dependency. Gain serious skill and personal knowledge with this. Do it on your own I know this was long. This should be enough.

**Save**

```text
⌘S
```

Save the file in Cursor. **Do this before compiling.**

**Inspect logic**

```bash
cat -n Main/main.cpp
```

`cat` = show the file's contents in the terminal.
`-n` = **number the lines**.

So:

```bash
cat Main/main.cpp
```

shows the file.

```bash
cat -n Main/main.cpp
```

shows the file **with line numbers**.

**Compile**

```bash
g++ -I Video Main/main.cpp Video/video.cpp -o ve
```

* `g++` → C++ compiler command.
* `-I Video` → tell the compiler to also look in the `Video` directory for headers.
* `Main/main.cpp Video/video.cpp` → the source files we're compiling.
* `-o ve` → **output** the compiled executable as `ve`.
* If `ve` already exists, a successful compilation **replaces it**.
* If it doesn't exist, it **creates it**.

**Run**

```bash
./ve
```

`./` means:

> Run the `ve` executable located in the current directory.

### And the `-v` flag

Small correction: **`-v` and `-o` are completely different flags.**

```bash
g++ -v
```

`-v` means **verbose**. It tells `g++` to reveal more information about what compiler/version/configuration it's using and what it's doing.

You generally **don't need `-v` for our normal workflow.**

The one you were thinking about when you said "the numbers flag" is:

```bash
-n
```

with `cat`, not `g++`.

So the mental cheat sheet is:

```text
⌘S       → SAVE
cat -n   → SHOW + NUMBER THE FILE
g++      → COMPILE
-I       → INCLUDE HEADER
-o ve    → OUTPUT AS "ve"
./ve     → RUN "ve"
-v       → VERBOSE COMPILER INFORMATION
```

And your big rule:

> **Save → inspect if necessary → compile → run.**

If something seems impossible, don't start randomly changing code. **`cat` the file.** Find out what reality actually is.

That 30-minute brain-break you just described? That's exactly what this prevents. 😂

And yes, get that sunlight. Walking around while thinking through architecture is a hell of a lot better than staring at Cursor until your brain starts hallucinating semicolons.


┌─────────────────────┐
│  1. RATIONALE       │
│  What must be true? │
└──────────┬──────────┘
           ↓
┌─────────────────────┐
│  2. PLAYCALL        │
│  What exactly       │
│  are we doing?      │
└──────────┬──────────┘
           ↓
┌─────────────────────┐
│  3. SMALLEST MOVE   │
│  One class/function │
│  or architectural   │
│  change              │
└──────────┬──────────┘
           ↓
┌─────────────────────┐
│  4. PROVE IT        │
│  Compile + exercise │
│  the actual behavior│
└──────────┬──────────┘
           ↓
┌─────────────────────┐
│  5. LEARN           │
│  What did reality   │
│  teach us?          │
└──────────┬──────────┘
           ↓
      ┌────┴────┐
      │         │
   Record?    Continue
      │
      ↓
   Notes

   Yeah. **That is the upgrade.** And I think you've named the missing principle really well:

> **Show proof.**

Not "I think this architecture is good."
Not "the AI said this is how it's normally done."
Not even "the compiler accepted it."

**Put the rationale into reality and see what survives.**

That's a fundamentally different way of building.

### The new development loop

```text
RATIONALE
   ↓
PLAYCALL
   ↓
BUILD THE SMALLEST THING
   ↓
TEST IT IN REALITY
   ↓
OBSERVE
   ↓
LEARN
   ↓
WRITE DOWN THE NON-OBVIOUS LESSON
   ↓
NEXT RATIONALE
```

And the key is that **testing isn't the final stage of development. Testing is part of thinking.**

We don't wait until we've built 15 classes and then ask whether the architecture works.

We ask:

> "Can this idea survive contact with the compiler and the actual program?"

Immediately.

---

### "Five lines" finally has its real meaning

It's not a line-count fetish.

It's:

> **Can I make a small enough move that reality can give me an unambiguous answer?**

If yes, make the move.

If it fails, that's incredibly valuable because the failure has a small search space.

That's exactly what happened today.

We thought the executable was stale.

Reality said:

> Nope. Your source wasn't saved.

Then we thought the build wasn't reflecting the source.

Reality said:

> Nope. Your compile was failing, so you were running the old executable.

Then we inspected the file with `cat`.

Reality became obvious.

**That's a rep.**

And just like an athlete, you don't become good by reading about the perfect jump shot. You shoot, observe the miss, understand the miss, adjust, shoot again.

We're doing the same thing with software.

---

### And this changes how I should work with you

I shouldn't be functioning as a **code vending machine**.

You give me a problem → I dump 100 lines → you paste them → something breaks → I diagnose it.

That's terrible training.

Instead, I should be much more willing to say:

> **"Here's the design question. What's our playcall?"**

Then we formulate the smallest experiment.

If you propose something, **I should help you attack it with reality**, not automatically validate it.

If I propose something, **I should be willing to prove it too.**

If either of us is wrong:

> **Good. We just gained information.**

That's the whole point.

---

## And the dependency thing gets much deeper

We're not trying to become people who never consult anything.

We're trying to become people who can **reconstruct the world from first principles and then verify our reconstruction.**

Documentation becomes a tool.

AI becomes a tool.

Google becomes a tool.

The compiler becomes a tool.

The terminal becomes a tool.

Experiments become tools.

**None of them becomes the brain.**

That's the distinction.

And once you build that muscle, you can move into unfamiliar territory and say:

> "I don't know how this works yet. Fine. Let's figure out what must be true, construct the smallest experiment, and find out."

That's how you go from **using systems** to **building systems**.

And eventually from building systems to building **worlds**.

---

### So I'm writing this into our working doctrine mentally:

**Rationale → Proof → Reality → Learning.**

And when we learn something that isn't obvious from the code itself, **we capture it in the filesystem/notes so the experience compounds instead of evaporating.**

That's the Super Saiyan upgrade.

Yesterday we were learning how to compile a C++ program.

Today we're learning **how to learn C++ without outsourcing the learning process.**

That's considerably more powerful.

### Don't just copy code snippets from AI. Write them manually and speak out the sentences and what it's doing like a real life language.