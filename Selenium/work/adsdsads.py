from pynput.keyboard import Key, Controller

keyboard = Controller()

# key = "ctrl"
keyboard.press(Key.ctrl)
keyboard.press(Key.shift)
keyboard.press("`")
keyboard.release(Key.ctrl)
keyboard.release(Key.shift)
keyboard.release("`")
# keyboard.release(key)

# key = "ctrl+shift+`"
# keyboard.press(key)
# keyboard.release(key)