import tbselenium.common as cm
from tbselenium.tbdriver import TorBrowserDriver
from tbselenium.utils import launch_tbb_tor_with_stem

tbb_dir = "C:\EV_Files\tor-browser-selenium"
tor_process = launch_tbb_tor_with_stem(tbb_path=tbb_dir)
with TorBrowserDriver(tbb_dir, tor_cfg=cm.USE_STEM) as driver:
    driver.load_url("https://gplinks.co/KBPqe")
tor_process.kill()