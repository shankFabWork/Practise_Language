def recaptcha_check(check):
    waiting = WebDriverWait(browser,1)
    try:
        for frame in browser.find_elements_by_tag_name('iframe'):
            browser.switch_to.default_content()
            browser.switch_to.frame(frame)
            for x in ['@class=','@id=','@name=','@for=','text()=']:
                try: waiting.until(EC.presence_of_element_located((By.XPATH,f"//*[{x}'{check}']")))
                except: continue
                else: return True
    except: return False

https://birdurls.com/ru1hZL