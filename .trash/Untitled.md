## Obsidian Execute Code Plugin

[](#obsidian-execute-code-plugin)

[![Obsidian Downloads](https://camo.githubusercontent.com/bdeaed2ea05eadcd619bac39ecfadf82e1d172aa8071489f05b7ded086dea8e6/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f64796e616d69632f6a736f6e3f636f6c6f723d383537326462266c6162656c436f6c6f723d316531653165266c6162656c3d446f776e6c6f6164732671756572793d2425354227657865637574652d636f6465272535442e646f776e6c6f6164732675726c3d68747470733a2f2f7261772e67697468756275736572636f6e74656e742e636f6d2f6f6273696469616e6d642f6f6273696469616e2d72656c65617365732f6d61737465722f636f6d6d756e6974792d706c7567696e2d73746174732e6a736f6e)](https://camo.githubusercontent.com/bdeaed2ea05eadcd619bac39ecfadf82e1d172aa8071489f05b7ded086dea8e6/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f64796e616d69632f6a736f6e3f636f6c6f723d383537326462266c6162656c436f6c6f723d316531653165266c6162656c3d446f776e6c6f6164732671756572793d2425354227657865637574652d636f6465272535442e646f776e6c6f6164732675726c3d68747470733a2f2f7261772e67697468756275736572636f6e74656e742e636f6d2f6f6273696469616e6d642f6f6273696469616e2d72656c65617365732f6d61737465722f636f6d6d756e6974792d706c7567696e2d73746174732e6a736f6e) [![GitHub package.json version](https://camo.githubusercontent.com/b99a6b254328dfc5fd828db4b399652bc2fc78a26c20fafb0197280454cc3509/68747470733a2f2f696d672e736869656c64732e696f2f6769746875622f7061636b6167652d6a736f6e2f76657273696f6e2f747769626972616c2f6f6273696469616e2d657865637574652d636f64653f636f6c6f723d383537326462266c6162656c436f6c6f723d316531653165266c6162656c3d43757272656e7425323056657273696f6e)](https://camo.githubusercontent.com/b99a6b254328dfc5fd828db4b399652bc2fc78a26c20fafb0197280454cc3509/68747470733a2f2f696d672e736869656c64732e696f2f6769746875622f7061636b6167652d6a736f6e2f76657273696f6e2f747769626972616c2f6f6273696469616e2d657865637574652d636f64653f636f6c6f723d383537326462266c6162656c436f6c6f723d316531653165266c6162656c3d43757272656e7425323056657273696f6e) [![GitHub Release Date](https://camo.githubusercontent.com/c3f1ba69bbf6c2c3b3304d2a595938f6691335e9da6ca4d49eb1891f5508afdd/68747470733a2f2f696d672e736869656c64732e696f2f6769746875622f72656c656173652d646174652f747769626972616c2f6f6273696469616e2d657865637574652d636f64653f636f6c6f723d383537326462266c6162656c436f6c6f723d316531653165266c6162656c3d4c617465737425323052656c65617365)](https://camo.githubusercontent.com/c3f1ba69bbf6c2c3b3304d2a595938f6691335e9da6ca4d49eb1891f5508afdd/68747470733a2f2f696d672e736869656c64732e696f2f6769746875622f72656c656173652d646174652f747769626972616c2f6f6273696469616e2d657865637574652d636f64653f636f6c6f723d383537326462266c6162656c436f6c6f723d316531653165266c6162656c3d4c617465737425323052656c65617365)

This plugin allows you to execute code snippets in code blocks in your notes. The plugin adds a 'run' button for code blocks in supported languages. Clicking them results in the code of the block being executed locally. After the execution the result of the execution is shown. An interactive input element is created when your code snippets reads expects user input.

The result is shown only after the execution is finished. It is not possible to enter text on the command line into the executed program now.

[![Video that shows how the plugin works.](https://github.com/twibiral/obsidian-execute-code/raw/master/images/execute_code_example.gif?raw=true)](https://github.com/twibiral/obsidian-execute-code/blob/master/images/execute_code_example.gif?raw=true)

---

The following [languages are supported](#supported-programming-languages-): C, C++, CSharp, Dart, F#, Golang, Groovy, Haskell, Java, JavaScript, Kotlin, Lean, Lua, Maxima, OCaml, Octave, Prolog, Python, R, Racket, Ruby, Rust, Scala, Shell (including Batch & Powershell), SQL, TypeScript, Wolfram Mathematica, Zig.

If you are new to MarkDown or Obsidian.md, you can go to the [Quickstart Guide](#quickstart-guide-) or take a look in to [some blogs and videos that feature this plugin](#featured-in)

Python, R, and Octave support embedded plots. All languages support ["magic" commands](#magic-commands-) that help you to access paths in obsidian or show images in your notes.

You can create code blocks that are executed before or after each code block of the same language and define [global code injections](#global-code-injection-and-reusing-code-blocks-).

New: You can enable [persistent output](#persistent-output-experimental) to store the output of a code block in the note and export it to PDF.

Take a look at the [changelog](https://github.com/twibiral/obsidian-execute-code/blob/master/CHANGELOG.md) to see what has changed in recent versions.

[Here](#misc-) you can find some other tools and plugins that are compatible with this plugin and might be useful for you.

  

If you like this plugin and use it a lot, please consider supporting me in continuing the development of this plugin. You can also sponsor a new feature or language integration directly, if you want to speed up the development for a specific feature you need.

[![GitHub Sponsors](https://camo.githubusercontent.com/0bc986b1d72613b468bce694465e0485f775505309a88596dc0a8b6bd69daeb3/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f73706f6e736f722d3330333633443f7374796c653d666f722d7468652d6261646765266c6f676f3d4769744875622d53706f6e736f7273266c6f676f436f6c6f723d7768697465)](https://github.com/sponsors/twibiral) [![Buy me a coffee](https://camo.githubusercontent.com/d00fd59acac7cf84dba67604c30c9940c63cef258a31b263ccb92e565a849a87/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f4275795f4d655f415f436f666665652d4646444430303f7374796c653d666f722d7468652d6261646765266c6f676f3d6275792d6d652d612d636f66666565266c6f676f436f6c6f723d626c61636b)](https://www.buymeacoffee.com/timwibiral)

## Featured In

[](#featured-in)

|[![Video by I Versus AI](https://camo.githubusercontent.com/a8c985e0d620e4d0c4f928d042b3aa3afdae922858bea6e3e561e8d65ed6791e/68747470733a2f2f696d672e796f75747562652e636f6d2f76692f65517a34654157335a446b2f302e6a7067)](https://www.youtube.com/watch?v=eQz4eAW3ZDk)|[![Video by Michel's Science Speedrun](https://camo.githubusercontent.com/8235fec1bdec35b42dab65ad1211404fdebb75330dae9ae43d99891dcef5edf7/68747470733a2f2f696d672e796f75747562652e636f6d2f76692f773776796176724d5971772f302e6a7067)](https://camo.githubusercontent.com/8235fec1bdec35b42dab65ad1211404fdebb75330dae9ae43d99891dcef5edf7/68747470733a2f2f696d672e796f75747562652e636f6d2f76692f773776796176724d5971772f302e6a7067)|[![Video by GlareDB](https://camo.githubusercontent.com/1eb4e1d98b4f619a7176b8247d94bd2b691c7b0f7a1c92e35dc8844776a2f0ea/68747470733a2f2f696d672e796f75747562652e636f6d2f76692f6c5271336d6c7663794a772f302e6a7067)](https://camo.githubusercontent.com/1eb4e1d98b4f619a7176b8247d94bd2b691c7b0f7a1c92e35dc8844776a2f0ea/68747470733a2f2f696d672e796f75747562652e636f6d2f76692f6c5271336d6c7663794a772f302e6a7067)|[![Video by 노마드 코더 Nomad Coders](https://camo.githubusercontent.com/345461bb7da7b753c1b3badf7e71ec5a48eb47e045d02e3a6a63bc2ebe44beb6/68747470733a2f2f696d672e796f75747562652e636f6d2f76692f715931505f436d4c3861512f302e6a7067)](https://camo.githubusercontent.com/345461bb7da7b753c1b3badf7e71ec5a48eb47e045d02e3a6a63bc2ebe44beb6/68747470733a2f2f696d672e796f75747562652e636f6d2f76692f715931505f436d4c3861512f302e6a7067)|
|---|---|---|---|
|"Escape ChatGPT. Make your own Code Interpreter EASY" by _I Versus AI_|"Obsidian & quarto integration" by _Michel's Science Speedrun_|"Write SQL Queries in...Obsidian?" by _GlareDB_|"인생 노트앱...드디어 찾았습니다..!" by _노마드 코더 Nomad Coders_|

In blogs:

- ["Why and how you should switch to Obsidian." by _Connero_](https://medium.com/@connero_44521/why-and-how-you-should-switch-to-obsidian-c857ae315afd)
- ["Using Obsidian: Coding Notes" by _Kera Cudmore_](https://www.codu.co/articles/using-obsidian-coding-notes-pqjyljkh)
- ["Obsidian and Jupyter Notebooks" by _Brian Carey_](https://medium.com/@biscotty666/obsidian-and-jupyter-notebooks-5d90ab3eab4c)

Are you featuring this plugin in your content? Let me know and I will add it here.

## Supported programming languages 💻

[](#supported-programming-languages-)

JavaScript

- Requirements: Node.js is installed and the correct path is set in the settings.

function hello(name) {
	console.log(`Hello ${name}!`);
}

hello("Bob")

- By default, Javascript runs in Notebook Mode. You can turn this off in the settings.

TypeScript

- Requirements: Node.js installed then run in command line `npm install typescript -g` and `npm install ts-node -g`. (`-g` means global installation)
- Problems: If you use your global node.js installation, and it doesn't work try to set your `ts-node` path in the settings to `npx ts-node` instead of `ts-node`.

let message: string = 'Hello, World!';
console.log(message);  Python

- Requirements: Python is installed and the correct path is set in the settings.

def hello(name):
	print("Hello", name)

if __name__ == "__main__":
	hello("Eve")

- By default, Python runs in Notebook Mode. You can turn this off in the settings.
- Plots with matplotlib/seaborn are embedded in the note by default. You can turn this off in the settings. Note that plots are only embedded when `plt.show()` is called.

import seaborn as sns
import matplotlib.pyplot as plt
sns.set_style("darkgrid")
iris = sns.load_dataset('iris')
sns.FacetGrid(iris, hue ="species", height = 5)
		.map(plt.scatter, 'sepal_length', 'petal_length')
		.add_legend()

plt.show()

[![Example of an embedded plot.](https://github.com/twibiral/obsidian-execute-code/raw/master/images/plotting_example.png?raw=true)](https://github.com/twibiral/obsidian-execute-code/blob/master/images/plotting_example.png?raw=true)

R

- Requirements: R is installed and the correct path is set in the settings.
- For cool additional features for R try out [the Ridian plugin](https://github.com/MichelNivard/Ridian)

hello <- function(name){
	print(paste("Hello", name, sep = " "))
}

hello("Bob")

- Plots can be embedded in the note by default. You can turn this off in the settings.

y = c(12, 15, 28, 17, 18)
x = 1:length(y)
plot(x, y, type="l")

C++

- Requirements: [Cling](https://github.com/root-project/cling) is installed and correct path is set in the settings.
- Code will be executed line-by-line without needing a main function.

#include <iostream>
#include <string>

using namespace std;

void hello(string name) {
	cout << "Hello " << name << "!\n";
}

hello("Alice);

- Main functions can be used as an entrypoint by toggling the option in settings.

#include <iostream>

void main() {
	std::cout << "Hello, World!" << std::endl;
}

C

- Requirements: [Cling](https://github.com/root-project/cling) is installed and correct path is set in the settings.
- Code will be executed line-by-line without needing a main function.

#include <stdio.h>

printf("Hello, World!");

- Main functions can be used as an entrypoint by toggling the option in settings.

#include <stdio.h>

int main() {
	printf("Hello, World!");
	return 0;
}

Java

- Requirements: Java **11 or higher** is installed and the correct path is set in the settings.

public class HelloWorld {
	public static void main(String[] args) {
		System.out.println("Hello World!");
	}
}

SQL - Requirements: Have some SQL database installed and the correct path is set in the settings. The default is set to PostgreSQL (`psql`). - Make sure you adapt the settings to your database (`-d mydatabase -U myuser -f`)The default is set to . ```sql SELECT * FROM table_name; ``` LaTeX

## LaTeX

[](#latex)

Requirements: LaTeX distribution like [MiKTeX](https://miktex.org/) or [TeX Live](https://www.tug.org/texlive/) is installed and the correct paths are set in the settings.

### Minimal example

[](#minimal-example)

Injects default document class. Consider setting _Crop to content_.

\begin{document}
Hello World!
\end{document}

[![Minimal example](https://github.com/twibiral/obsidian-execute-code/raw/master/images/figure_minimal_example.svg)](https://github.com/twibiral/obsidian-execute-code/blob/master/images/figure_minimal_example.svg)

### Name output file

[](#name-output-file)

Set filename with `\title{…}`. Adds prefix `figure` to avoid file name collisions, group all generated files, and for appearance CSS selectors. Click run again will overwrite the file, and refresh its embeddings in the active view.

```
![[figure time of day.svg]]
```

\documentclass[border=2pt]{standalone} \title{time of day}
\usepackage{datetime2}
\begin{document}
The time is \DTMcurrenttime.
\end{document}

[![Time of day](https://github.com/twibiral/obsidian-execute-code/raw/master/images/figure_time_of_day.svg)](https://github.com/twibiral/obsidian-execute-code/blob/master/images/figure_time_of_day.svg)

### Include attachments

[](#include-attachments)

Include files relative to the vault's attachment folder. Consider [listings](http://mirrors.ctan.org/macros/latex/contrib/listings/listings.pdf) for source code listings, [markdown](http://mirrors.ctan.org/macros/generic/markdown/markdown.html) for inputting markdown files as LaTeX code, and `\input{…}` to paste plaintext or LaTeX source files. Layout with [graphbox](http://mirrors.ctan.org/macros/latex/contrib/graphbox/graphbox.pdf) for vertical alignment, or [tabularray](http://mirrors.ctan.org/macros/latex/contrib/tabularray/tabularray.pdf) for more complex alignment.

\documentclass{standalone} \title{include_attachments}
\usepackage{graphicx}
\begin{document}
\includegraphics{figure time of day.pdf} \quad
\includegraphics{figure time of day.pdf}
\end{document}

[![Include attachments](https://github.com/twibiral/obsidian-execute-code/raw/master/images/figure_include_attachments.svg)](https://github.com/twibiral/obsidian-execute-code/blob/master/images/figure_include_attachments.svg)

### Automatically reruns to get cross-references right.

[](#automatically-reruns-to-get-cross-references-right)

For instance reference a label that appears later in the document. The plugin detects `LaTeX Warning: Label(s) may have changed. Rerun to get cross-references right.` during compilation and reruns until resolved.

\documentclass{article} \title{sum of two poisson distribution}
\usepackage{mathtools,amsfonts}
\begin{document}
As seen in \eqref{eq:poisson}, we use convolutions of probability distributions for two independent poisson distributed random variables.
\begin{align*} \MoveEqLeft
\mathbb{P}(X + Y = k) = \sum_{m = 0}^\infty \mathbb{P}(X = m)\, \mathbb{P}(X = m - k) \tag{1}\label{eq:poisson} \\&
= \sum_{m = 0}^k \frac{\lambda^m\, e^{-\lambda}}{m!} \cdot \frac{\mu^{k - m}\, e^{-\mu}}{(k - m)!} = \ldots 
\end{align*} 
\end{document}

[![Sum of two poisson distributions](https://github.com/twibiral/obsidian-execute-code/raw/master/images/figure_sum_of_two_poisson_distributions.svg)](https://github.com/twibiral/obsidian-execute-code/blob/master/images/figure_sum_of_two_poisson_distributions.svg)

Not all rerun requirements are easy to detect. Consider adding the package [lastpage](http://mirrors.ctan.org/macros/latex/contrib/lastpage/lastpage.pdf) to force a rerun, by creating an unresolved reference.

\documentclass{article} \title{rerun sidenotes table}
\usepackage{sidenotes,tabularray,lipsum,lastpage}
\begin{document} \SetTblrInner{hlines}
\sidenotetext{This is a marginal note.} \lipsum[1][1-3] 
\begin{table*}
\begin{tblr}[tall, caption={Expand table into page margins}]{X}
    \lipsum[3][1-4]
\end{tblr}
\end{table*}
\end{document}

[![Sum of two poisson distributions](https://github.com/twibiral/obsidian-execute-code/raw/master/images/figure_sidenotes_comparison.svg)](https://github.com/twibiral/obsidian-execute-code/blob/master/images/figure_sidenotes_comparison.svg)

Explore [more LaTeX examples](https://antonpusch.de/latex), consult [package documentations](https://texdoc.org/), or learn about [LuaLaTeX](http://mirrors.ctan.org/obsolete/info/luatex/lualatex-doc/lualatex-doc.pdf).

More supported languages... CSharp

- Requirements: install dotnet core sdk and run in command line `dotnet tool install -g dotnet-script`, then config dotnet-script fullpath.

Console.WriteLine("Hello, World!");  Dart

- Requirements: dart sdk is installed and the correct path is set in the settings.

void main() {
  print("Hello World");
}

Lua

- Requirements: install lua and config lua path.

Lean

- Requirements: install lean and config lean path.

def main : IO Unit :=
  IO.println s!"Hello, World!"

#eval main

Shell

- Requirements: Set the path to your preferred shell in the settings. Default is Bash. (Only on Linux and macOS)

echo "Hello World!"
ls -la

Powershell

- Requirements: Used to execute shell commands on Windows. Default is Powershell but can be set to your preferred shell in the settings.
- On macOS: You probably need to change the command to use from `powershell` to `pwsh` in the plugin settings. Make sure you set the right path.

- If you prefer batch: change the path settings in the menu for powershell [![Example how to use the magic commands.](https://github.com/twibiral/obsidian-execute-code/raw/master/images/batch_settings.png?raw=true)](https://github.com/twibiral/obsidian-execute-code/blob/master/images/batch_settings.png?raw=true) Batch

- **Requirements**: Used to execute batch commands on Windows (also known as BAT or CMD). Default is command prompt, but can be set to your preferred shell in the settings.
- **Important**:  
    The percent sign is used in batch files to represent command line parameters: e.g. %1, %2, ...  
    Two percent signs in a batch file are treated like a single percent sign in a command: e.g. %%f  
    When using variables in execute code, use 2 percent signs. More info [here](https://stackoverflow.com/questions/14509652/what-is-the-difference-between-and-in-a-cmd-file)  
    

Prolog

- Requirements: NO requirements, works with [Tau-Prolog](https://github.com/tau-prolog/tau-prolog).
- Important: Add your queries after a line "`% query`" in the code block like in the following

likes(john, pizza).
likes(john, cheese).
likes(jane, beer).

% query
likes(john, X).

Groovy

- Requirements: Groovy is installed and the correct path is set in the settings.

def hello(name){  
	println "Hello ${name}!" 
}  

def helloClosure = {  
	println "Hello ${it}!" 
}  
  
hello("Bob")
  
helloClosure "Bob"

Golang

- Requirements: Golang is installed and correct path is set in the settings(`go` binary is available).
- Every code block must contain package declaration and a main function.

package main

import "fmt"

func main() {
	fmt.Println("Hello World")
}

Rust

- Requirements: Cargo is installed and correct path is set in the settings(`cargo` binary is available).
- `cargo-eval` is installed. Install using `cargo install cargo-eval`.
- Import statements and external crates is supported by `cargo-eval`. Read their [documentation](https://github.com/reitermarkus/cargo-eval).
- Every code block must have a main function.

fn main() {
	println!("Hello World");
}

Kotlin

- Requirements: Kotlin is installed and correct path is set in the settings.

hello(name: String) {
	println("Hello $name!")
}

hello("Bob")

Wolfram Mathematica

- Requirements: Mathematica is installed and correct path is set in the settings.
- You can add `-cloud` as argument in the settings to use the Wolfram Cloud instead of the local installation.

Haskell

- You can either use **runghc** (compiler) or **ghci** (interpreter) to run your code.
    - **runghc** requirements:
        - runghc and ghc are installed and correct paths are set in the settings.
        - Every code block must contain a main function.
    - **ghci** requirements:
        - ghci is installed and correct path is set in the settings.
        - If you have a main function you have to manually call it.

mySum:: Num a => a -> a -> a
mySum a b = a+b

Scala

- Requirements: Scala is installed and the correct path is set in the settings.

Racket

- Requirements: Racket is installed and the correct path is set in the settings.

Ruby

- Requirements: Ruby is installed and the correct path is set in the settings.

PHP

- Requirements: PHP is installed and the correct path is set in the settings.

<?php
echo "Hello, World!";
?>

Octave

- Requirements: Octave is installed and the correct path is set in the settings.

```
exp(i*pi)

x = -10:0.1:10;
plot (x, sin(x));
```

(Thanks to Michael M. Tung for the code example.)

- Figures are set to invisible by default. They are store in a file and directly embedded in the note.

Maxima

- Requirements: Maxima is installed and the correct path is set in the settings.

```
integrate(x,x);
plot2d(sin(x), [x,0,%pi]);
```

(Thanks to Michael M. Tung for the code example.)

- By default, plots are saved in a file and directly embedded in the note.

OCaml

- Requirements: OCaml is installed and the correct path is set in the settings.

print_endline "Hello, OCaml!"

Swift

- Requirements: Swift is installed and the correct path is set in the settings.

Squiggle: For Squiggle support take a look at the [Obsidian Squiggle plugin](https://github.com/jqhoogland/obsidian-squiggle) by @jqhoogland.

## Magic Commands 🪄

[](#magic-commands-)

Magic commands are some meta commands that can be used in the code block. They are processed by the plugin before the source code is executed.

The following magic commands are supported:

- `@vault_path`: Inserts the vault path as string (e.g. "/User/path/to/vault")
- `@vault_url`: Inserts the vault url as string. (e.g. "app://local/path/to/vault")
- `@note_path`: Inserts the vault path as string (e.g. "/User/path/to/vault/Note.md")
- `@note_url`: Inserts the vault url as string. (e.g. "app://local/path/to/vault/Note.md")
- `@title`: Inserts the note title as string.
- `@show(ImagePath)`: Displays an image at the given path in the note.
- `@show(ImagePath, Width, Height)`: Displays an image at the given path in the note.
- `@show(ImagePath, Width, Height, Alignment[center|left|right])`: Displays an image at the given path in the note.
- `@html(HtmlSource)`: Displays HTML in the note
- `@content`: Inserts the html content of the note in the code block. ([Here you find a nice example for the usage of this command.](https://github.com/twibiral/obsidian-execute-code/pull/390))

(`@show(...)` and `@html(...)` are only supported for JavaScript and Python yet.) (The old commands `@note` and `@vault` are still supported, but may be removed in the future.)

Examples for the magic commands with Python:

print("Vault path:", @vault_path)
print("Vault url:", @vault_url)

print("Note path:", @note_path)
print("Note url:", @note_url)

print("Note title:", @title)

@show("image.png")
@show("image.png", 100, 100)
@show("https://upload.wikimedia.org/wikipedia/commons/d/de/TestScreen_square.svg", 10%, 10%, "center")

@html("<h1>HTML Caption</h1>")
@html('''
<svg width="100%" height="100%" viewBox="0 0 600 600" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink">
  <circle cx="300" cy="300" r="250" style="fill:peru;" />
  <circle cx="200" cy="250" r="50" style="fill:black;" />
  <circle cx="400" cy="250" r="50" style="fill:black;" />
  <circle cx="190" cy="230" r="20" style="fill:white;" />
  <circle cx="390" cy="230" r="20" style="fill:white;" />
  <circle cx="250" cy="400" r="85" style="fill:saddlebrown;" />
  <circle cx="350" cy="400" r="85" style="fill:saddlebrown;" />
  <ellipse cx="300" cy="380" rx="50" ry="35" style="fill:black;" />
  <ellipse cx="130" cy="100" rx="110" ry="70" style="fill:saddlebrown;"/>
<ellipse cx="470" cy="100" rx="110" ry="70" style="fill:saddlebrown;" />
</svg> 
''')

Try it out yourself!

[![Example how to use the magic commands.](https://github.com/twibiral/obsidian-execute-code/raw/master/images/magic_example.png?raw=true)](https://github.com/twibiral/obsidian-execute-code/blob/master/images/magic_example.png?raw=true)

## Running in Preview ⏩

[](#running-in-preview-)

Adding `run-` before the language name in the code blocks (as in the example below) renders the code block in the preview already. This allows you to execute the code in the preview.

````
```run-python
def hello(name):
print("Hello", name)

    if __name__ == "__main__":
        hello("Eve")
````

## Code Block Arguments 🏷

[](#code-block-arguments-)

Code blocks support specifying additional arguments in the form `{key='value', otherkey=['val1', 'val2']}`. Add them to code blocks like so:

````
```python {label='my label'}
print('my labelled code block')
```
````

## Global Code Injection and Reusing Code Blocks 📘

[](#global-code-injection-and-reusing-code-blocks-)

Sometimes it is helpful to have code that is executed before or after each other block of the same language. This plugin supports this in a few ways:

### Global Injection in the Settings

[](#global-injection-in-the-settings)

All languages have a 'global inject' option in the settings that allows defining code to be added to the top of every single code block on a per-language basis. Code reuse fully works with all languages, and all existing magic commands, including showing images, and inline plot outputs. This can be used to define e.g. often used functions or import your favourite packages or libraries.

### Note-wide Pre- and Post-Code Blocks

[](#note-wide-pre--and-post-code-blocks)

You can specify the `pre` argument to create a block that is executed before each following code block:

````
```python {pre}
import pandas as pd
```
````

This code block is added before each python block you define below in the note and import the pandas package.

`post` blocks work the same way, but the code in post blocks is executed _after_ your other code blocks.

Pre-/post-blocks will only apply to code blocks defined below them, and will only apply to code blocks from the same language.

You can also have a pre- and post-block at the same time by specifying `{pre, post}`

Note, the `pre`/`post` arguments are special in that you don't need to explicitly state a key/value pair, however you can do so if you wish:

`{pre}` is equivalent to `{export='pre'}`, `{pre, post}` is equivalent to `{export=['pre', 'post']}`.

### Labelled Code Blocks

[](#labelled-code-blocks)

You can label specific code blocks with the `label='string'` argument, then import them explicitly in other blocks with the `import='string'` or `import=['string1', 'string2', ...]` argument so they aren't automatically imported as with pre-/post-blocks:

````
```python {label='block 1'}
print('running block 1')
```

```python {label='block 2'}
print('running block 2')
```

```python {import=['block 1', 'block 2']}
print('should run block 1 and 2')
```
````

Labelled code blocks will be executed before the code block being run, however after global injects and pre blocks.

### Ignoring Code Exports

[](#ignoring-code-exports)

In case you want to manually ignore specific exports in a code block like pre / post / global exports, you can do so with the `ignore` argument that accepts either `pre`, `post`, `global`, an array of any of these 3, or `all` to ignore all exports:

````
```python {ignore='all'}
print('should not run any global injects or pre / post blocks')
```

```python {ignore=['global', 'pre']}
print('should not run any pre blocks or global injects')
```
````

### Notebook Mode

[](#notebook-mode)

A few languages (currently JS and Python) support _Notebook Mode_. If a language is using Notebook Mode (configurable in Settings), then all code blocks in a given file will execute in the same environment.

Variables functions, etc. defined in one code block will be available in other code blocks. Code blocks are executed on demand; the order of code blocks in the file does not affect the order in which they are executed:

````
```js
console.log(f)
```
```js
var f = 3;
```
````

Running the first code block, then the second, then the first again will give:

```
Uncaught ReferenceError: f is not defined
undefined
3
```

To manage the open runtimes for Notebook Mode, you can use the `Open Code Runtime Management` command in the command palette. From this sidebar window, you can stop kernels. **Note: force-stopping requires `taskkill` on Windows and `pkill` on Unix. 99% of systems should have these preinstalled: if yours doesn't, please [file an issue](https://github.com/twibiral/obsidian-execute-code/issues/new/choose)**

### Persistent Output [Experimental]

[](#persistent-output-experimental)

Since version 2.0.0, the plugin supports persistent output. This means that the output of a code block is stored in the note and will be displayed when you open the note again. This is useful for long-running code blocks or code blocks that produce a lot of output. The output is stored in the note as a comment and will be displayed in the preview mode.

To enable this feature, you have to enable the setting `Persistent Output` in the plugin settings. We recommend reopening open notes that contain code blocks after enabling this feature.

⚠ This feature is still experimental and may not work as expected in all cases! We recommend that you disable this feature if you encounter any problems.

## Misc 📦

[](#misc-)

### Style Settings 🎨

[](#style-settings-)

This plugin supports customising styles using the [Style Settings plugin](https://github.com/mgmeyers/obsidian-style-settings) or the [Obsidian Code Styler plugin](https://github.com/mayurankv/Obsidian-Code-Styler).

### Other Tools

[](#other-tools)

Take a look at the [Obsidian Tools python package](https://github.com/mfarragher/obsidiantools) to find some useful tools for interacting with your vault.

## Quickstart Guide

[](#quickstart-guide)

Start by checking if the plugin is installed and **activated**. Continue by creating a code block in your preferred language. Check above to see if the language is supported.

Now you can switch from the preview mode to the rendered mode (where you can't edit the text anymore). Now, when you hover over the code block, you should see a button labeled "run". Click it!

If it didn't work and a warning appears (that is not related to a bug in your code), you probably need to set the correct execution part for the language (e.g., "C://User/YourName/anaconda/python.exe" or something like that). You can find instructions about how to find the right path below.

Now it works, great! Feel free to read or skim through the text above to learn more features you might like, for example persistent output or embedding of plots.

## Installation 💾

[](#installation-)

In your vault go to Settings > Community plugins > Browse and search for "Execute Code". Select the plugin, install it and activate it.

or

Follow [this link](https://obsidian.md/plugins?search=execute%20code#) and click "Open in Obsidian".

## Locating Path Settings ( ex. JavaScript | Node )

[](#locating-path-settings--ex-javascript--node-)

To avoid or resolve errors from an incorrect path.

('where' for Mac and Windows) --- (for Linux Users, replace 'where' with 'which')

1. In your terminal, type 'where node' [![Type 'where node' in terminal](https://github.com/twibiral/obsidian-execute-code/raw/master/images/path_location_shell.png?raw=true)](https://github.com/twibiral/obsidian-execute-code/blob/master/images/path_location_shell.png?raw=true)
2. Copy path from terminal ( ex. /opt/homebrew/bin/node )
3. Paste in path under settings ( ex. Node path ) [![Update path under settings with path from step 2](https://github.com/twibiral/obsidian-execute-code/raw/master/images/path_location_settings.png?raw=true)](https://github.com/twibiral/obsidian-execute-code/blob/master/images/path_location_settings.png?raw=true)

## Warning ⚠

[](#warning-)

Do not execute code from sources you don't know or code you don't understand. Executing code can cause irreparable damage.

## Known Problems 🛠

[](#known-problems-)

- On Linux, Snap/Flatpak/AppImage installations of Obsidian run in an isolated environment. As such, they will not have access to any of your installed programs. If you are on Linux, make sure to install the `.deb` version of Obsidian. If your distro isn't compatible with `.deb` files, you may see issues.
- Missing when `run` button after switching the theme: Try to close and reopen your notes and wait for a few minutes. It seems like obsidian doesn't call the postprocessors after the theme switch.
- Pre-/Post-blocks may not be executed if the file contains duplicate code blocks.
- In Python, Embed Plots may not be off while Notebook Mode is on

## Contribution 🤝

[](#contribution-)

All contributions are welcome. Just create a merge request or email me: contact(at)tim-wibiral.de

The [open issues](https://github.com/twibiral/obsidian-execute-code/issues) are a good starting point to find something to work on. Some are marked as ["good first issue"](https://github.com/twibiral/obsidian-execute-code/labels/good%20first%20issue) and are easier to solve.

## Contributors ♥

[](#contributors-)

[![List of contributors to this project.](https://camo.githubusercontent.com/4bf5dd949a0fdb4fce62bd4523b54876e79f31ca11ea5a60d45b9fb8e14b342f/68747470733a2f2f636f6e747269622e726f636b732f696d6167653f7265706f3d747769626972616c2f6f6273696469616e2d657865637574652d636f6465)](https://github.com/twibiral/obsidian-execute-code/graphs/contributors)

Made with [contrib.rocks](https://contrib.rocks/).