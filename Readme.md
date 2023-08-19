# Cengine (C++ Local Search Engine)

Inspired from [Seroost by Tsoding](https://github.com/tsoding/seroost), this is a C++ implementation of the same idea.
I have cloned the documentation of [doc.gl](https://doc.gl) and have made a local search engine for it.

## Dependencies

- [RapidXml v1.13](http://rapidxml.sourceforge.net/) - For parsing the XML files

## Usage

- Clone the repository, and cd into it.
- Run the following command to build the project:

```bash
make
```

- Or, build and run the project:

```bash
./run.sh
```

## Usage

Follow these steps to set up and use the Search Engine project. For more detailed information about using Premake, you can refer to the official [Premake documentation](https://premake.github.io/docs/Using-Premake).

### Prerequisites

- Git: Make sure you have Git installed. If not, you can download and install it from [here](https://git-scm.com/downloads).

### Installation

1. Clone the repository:

```sh
git clone https://github.com/PriyanshuSharma23/Cengine.git
```

### Building Workspace

1. Navigate to the Cengine directory:

   ```sh
   cd Cengine
   ```

2. Generate the project files using Premake. For example, to generate Makefiles:

   ```sh
    ./vendor/bin/premake5/premake5 gmake
   ```

3. Build the workspace:

   ```sh
   make config=debug all
   ```

   or

   ```sh
   make config=release all
   ```

4. Run the Cli:

   ```sh
   ./Cli/bin/Debug/Cli
   ```

   or

   ```sh
   ./Cli/bin/Release/Cli
   ```

### Building the Search Engine Core

1. Navigate to the SearchEngineCore directory:

   ```sh
   cd SearchEngineCore
   ```

2. Generate the project files using Premake. For example, to generate Makefiles:

   ```sh
   ../vendor/bin/premake5/premake5 gmake
   ```

3. Build the Search Engine Core:

   ```sh
   make
   ```

### Building the Command Line Interface (CLI)

1. Navigate to the Cli directory:

   ```sh
   cd Cli
   ```

2. Generate the project files using Premake:

   ```sh
   ../vendor/bin/premake5/premake5 gmake
   ```

3. Build the CLI:

   ```sh
   make
   ```

### Running the CLI

> Note: Make sure you have built the Search Engine Core and the CLI before running the CLI.

1. Navigate to the Cli/bin/Debug (or Cli/bin/Release) directory:

   ```sh
   cd bin/Debug
   ```

2. Run the CLI:

   ```sh
   ./Cli
   ```
