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
* (Optional) Switch the workspace to the root of the git repository
* In Momentics, select File -> Import -> Existing Projects into Workspace and point the browser to the root of the repository. You should be presented with the option to import telegram-blackberry10 as a project

## Contributing guidelines

* For every feature, please create a new branch.
    * Name the branch based on the type of feature you're implementing in the format `type/short_name` where type is either ui, service or other and short_name is a short description of the issue you're fixing.
    * If you need to continue work and you depend on an unmerged branch, you can try branching from master and then merging the branches you need.
* Once you're ready, create a Pull request for the branch. Once enough people confirm validity of the branch, it will be merged.
	* Remember to mention any fixes your PR solves in the message so that they get automatically closed.
* Keep the code formatted using the built-in formatter.
* Keep the commits small and atomic.
* Make sure that commit messages are descriptive of what the commit accomplishes.
