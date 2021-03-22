## tomatoclock
A linux command line count down tomatoclock and script runner.

![logo](./tomatoclock.png)

#### Dependencies
[termbox](https://github.com/nsf/termbox/tree/master/src)

#### Build:
```
mkdir build
cd build
cmake ..
make install
```

#### Usage:

##### Command line options
Most options are opotional. If you don't supply a duration the default duration will be sete to 10 minutes. Once a count down starts, tomatoclock will watch it at background until the duration elapsed. You can have multiple tasks running at the background.

```
$ tomatoclock --help
  usage: coutdown <time> [OPTIONS]

  args:
    -m <timeformat>             countdown by minutes, format mm:ss
    -h <timeformat>             countdown by hour, format hh:mm:ss or hh:mm
    -c <script>                 the shell script to run when the count is finished
    -s <scriptfile>             shell script file
    -h                          print this message
    -t                          display tui
    -l                          list current status
    -t <text>                   extra message to show on the tui.
    -r                          show history
```

##### TUI Shortcuts
Tomatoclock provides a tui to help you manage your count down tasks. You can view the timer, mangage tasks, and look at histories. It's not necessary to display the tui, if you've setup some tasks at the background with `$ tomatoclock 10m30s`, you can view them at anytime with `$tomatoclock -t`.

tomatoclock is a singleton process, there can be multiple tasks, but only one main process running at a time. Running the program mulitple times will by default add new tasks to the current instance.

Here is a table of shortcuts:
```
:l          list current counting down tasks
:h          view a list of history
:q          quit
```

Whenever there is a list, you can use either arror keys or `hjkl` to navigate, use `enter` to see more details.


#### Functionalities:
- [] count down n seconds and trigger a shell script on finished.
- [] show a tui screen for time remaining.
- [] count down minutes, hours, and days.


#### Styles:

###### Style 1 (default)
```
$ tomatoclock 1s -t -m "watch rick and morty"

     ██████   ██████      ██████     ██
     ██  ██   ██  ██  ██  ██  ██     ██
     ██  ██   ██  ██      ██  ██     ██
     ██  ██   ██  ██  ██  ██  ██     ██
     ██████   ██████      ██████     ██

        - watch rick and morty -
```
