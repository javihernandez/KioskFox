const kioskUriWhiteList = ["data","javascript","http","https","ftp","wyciwyg"];
const kioskKeyWhitelist = [ "key_fullZoomReduce","key_fullZoomEnlarge","key_find",
                            "key_findAgain","key_findPrevious","key_reload","goBackKb",
                            "goForwardKb","key_stop","key_newNavigatorTab","key_search",
                            "key_search2","key_undo","key_redo","key_cut","key_copy",
                            "key_paste","key_delete","key_selectAll","key_fullZoomReset"
                          ];

var kioskTabProgressListener = {
  onLocationChange : function(aBrowser, aProgress, aRequest, aURI) {
    if(kioskUriWhiteList.indexOf(aURI.scheme) == -1 && aURI.spec != "about:blank" && aURI.spec != "about:home") {
      loadURI("file:///usr/share/zona-autogestion/index.html");
    }
  }
};

var kioskSearchEngineObserver = {
  observe: function(aEngine, aTopic, aVerb) {
    if (aTopic == "browser-search-engine-modified") {
      aEngine.QueryInterface(Ci.nsISearchEngine);
      if(aVerb == "engine-added") {
        //if someone adds an engine simply remove it.
        let searchService = Cc["@mozilla.org/browser/search-service;1"].getService(Ci.nsIBrowserSearchService);
        searchService.removeEngine(aEngine);
      }
    }
  }
};

function kioskInsertToolbarItem(itemId,afterId)
{
  try {
    var navBar  = document.getElementById("nav-bar");
    var curSet  = navBar.currentSet.split(",");

    if (curSet.indexOf(itemId) == -1) {
      var pos = curSet.indexOf(afterId) + 1 || curSet.length;
      var set = curSet.slice(0, pos).concat(itemId).concat(curSet.slice(pos));

      navBar.setAttribute("currentset", set.join(","));
      navBar.currentSet = set.join(",");
      document.persist(navBar.id, "currentset");
      try {
        BrowserToolboxCustomizeDone(true);
      }
      catch (e) {}
    }
  }
  catch(e) {}
}

function kioskInitialize()
{
  Components.utils.import("resource://kioskfox/kiosk_module.js");
  
  //This handles the case where showModalDialog and a specially crafted open call can force a page 
  //to open up a in a new window regardless of the browser settings.
  //I have a filed a bug report for this but it probably won't be fixed anytime soon.
  
  //The below code will force firefox to only have the one main window open at all times.
  if(gUtilities.init == false) {
    //cache the gBrowser so we always reference the main browser window
    //when a new one tries to open and reload this extension
    gUtilities.init = true;
    gUtilities.browser = gBrowser;
  }else{
    window.close();
    try {
      //display a new notification on the true browser window
      let nb = gUtilities.browser.getNotificationBox();
      const message = 'Due to the way Firefox handles some new windows, a window could not be opened in a new tab and was closed to protect this kiosk\'s integrity.  Sorry for any inconvenience this may cause.';
      const priority = nb.PRIORITY_WARNING_HIGH;
      nb.appendNotification(message, 'popup-blocked','resource://kioskfox/key.png',priority, null);
    } catch(err) { }
    return;
  }

  //Disable personas
  LightWeightThemeWebInstaller = function() { return false; }
  
  let os = Cc["@mozilla.org/observer-service;1"].getService(Ci.nsIObserverService);
  os.addObserver(kioskSearchEngineObserver, "browser-search-engine-modified", false);
  
  //Make the browser fullscreen.
  //This needs to be fixed when I port to firefox 4.0.
  //There was actually a bad bug in the beta. Remember to file a bug report about it.
  setTimeout(function() { window.maximize(); }, 1000);
  BrowserFullScreen();
  
  //Disable print,open,and save.
  //will not work in a non-windows environment, but it doesn't need to,
  //as I don't think you can execute items from the open and save dialogs
  //in linux.
  try {
    let obj = Cc["@ohnull.com/kioskfox/lockcomponent;1"].createInstance();
    obj = obj.QueryInterface(Components.interfaces.kioskcomp);
    obj.LockDialogs();
  } catch(err) { }

  //Whitelists certain uri schemes, blacklist all others
  //This is limiting us to Firefox 3.5 and up.
  gBrowser.addTabsProgressListener(kioskTabProgressListener);
  
  //disables shortcut keys that are not whitelisted.
  let keyElems  = document.getElementsByTagName("key");
        
  for(var i = 0; i < keyElems.length; i++) {
    let keyId = keyElems[i].getAttribute("id");
    if(kioskKeyWhitelist.indexOf(keyId) == -1)
      keyElems[i].setAttribute("disabled","true");
  }

  //customize the gui and prevent resizing of the search widget
  kioskInsertToolbarItem("logout-button",null);
}

window.addEventListener("load",kioskInitialize,false);
