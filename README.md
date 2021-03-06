tgBB10
======

Unofficial Telegram client for the BlackBerry 10 platform

## Set up

The application was developed using the Momentics IDE. Instructions for that IDE follow. If you manage to get it to run in some other environment (e.g. Visual Studio), feel free to append the instructions.

### Momentics

Prerequisites:

* Momentics 2.1.1
* BlackBerry 10.2 SDK

Steps:

* Clone the repository
* (Optional) Pull in the git submodules with `git submodule init` and `git submodule update`
* (Optional) Switch the workspace to the root of the git repository
* In Momentics, select File -> Import -> Existing Projects into Workspace and point the browser to the root of the repository. You should be presented with the option to import telegram-blackberry10 as a project, as well as the telegram-qt4 library
* In order to link the project to the library properly, it is necessary to generate it's src directory and build the library for all device variants. See the following section for more details.

#### Building and linking the telegram-qt4 library project

In order to connect to the Telegram API, this project relies on the project telegram-qt4 available here: [https://github.com/Kaffeine/telegram-qt](https://github.com/Kaffeine/telegram-qt).

A version of that project modified to be used as a BlackBerry 10 library project is available in the directory [telegram-qt4](telegram-qt4). However, this project doesn't contain any code since all of it can be generated from the library itself.

In order to generate the library project, a bash script is provided under [support/update-telegram-qt4.sh](support/update-telegram-qt4.sh). Simply run this script from anywhere in the project and the necessary files should be generated. Since this needs to be run **every time the revision changes**, a post-checkout hook is provided under [support/git/hooks/post-checkout](support/git/hooks/post-checkout). Copy this into your local .git repository (present in the project root) and the process will run automatically on every checkout.

Unfortunately, Momentics won't automatically build all the proper versions of the library project so we need to do this manually.

Steps:

* Right click on the telegram-qt4 project, select properties
* Under the C/C++ Build section, select Environment and then Manage configurations
* Set it to Device-Release
* Close the dialog and perform a build of the project (CTRL+b or Project -> Build Project)
* Repeat these steps, but set the configuration to Simulator-Debug

After this, the main project should properly link against the library and build without errors.

##### Configuring the build order

Momentics may get the build order wrong and try to build the application project before building the library project during a clean.

To fix this, open the application project's properties and under the section _Project References_ add a checkmark next to telegram-qt4.

#### Connecting to the Telegram API

By default the app will connect to an internal mock API since this eases UI development and testing.

In order to connect to the actual API, the following steps need to be taken:

1. Open the [telegram-blackberry10/src/config.hpp](telegram-blackberry10/src/config.hpp) file and change the defines so that TG_API_TG is defined and TG_API mock is not
2. Copy the example configuration file [telegram-blackberry10/src/app_secrets.example.hpp](telegram-blackberry10/src/app_secrets.example.hpp) into telegram-blackberry10/src/app_secrets.hpp.
3. Open the configuration file and replace the placeholder values with those you obtained on [my.telegram.org](https://my.telegram.org).

Now the app should build, run and use the Telegram API. If you experience problems, check the console for debug information.

## Contributing guidelines

* For every feature, please create a new branch.
    * Name the branch based on the type of feature you're implementing in the format `type/short_name` where type is either ui, service or other and short_name is a short description of the issue you're fixing.
    * If you need to continue work and you depend on an unmerged branch, you can try branching from master and then merging the branches you need.
* Once you're ready, create a Pull request for the branch. Once enough people confirm validity of the branch, it will be merged.
	* Remember to mention any fixes your PR solves in the message so that they get automatically closed.
* Keep the code formatted using the built-in formatter.
* Keep the commits small and atomic.
* Make sure that commit messages are descriptive of what the commit accomplishes.

## Issue tracking and priorities

All features that need to be implemented should be listed under issues, each under their respective milestones.

There are currently three types of milestones - UI milestones, Service milestones and Other.

UI milestones contain issues which can be solved by only implementing the UI part - no logic is necessary. If you depend on some data, mock it.

Service milestones contain issues which (mostly) rely on communication with the Telegram API. When solving these issues, you shouldn't edit UI parts, as integration should be a different issue.

Other contains mostly unsorted things which would be nice to have and push notifications which are an important feature.

If you notice an error in an issue, feel free to comment on them. If you think an issue should be added, feel free to open one.

### Labels

Several labels are in use.

The *user interface* label is assigned to issues which are related to UI features.
The *service* label is assigned to issues regarding backend logic.
The *required* label is assigned to features of higher priority which need to be implemented in the minimum product.
The *missing info* label is assigned to issues where a part of the info is missing or is not clear. See if you can clarify these.
Finally, the *nice to have* label is assigned to features which increase the value of the product, but are not essential. Only work on these if you know you'll have the time.

## License

This project is released under GPLv3. Details are available in the file [LICENSE](LICENSE).
