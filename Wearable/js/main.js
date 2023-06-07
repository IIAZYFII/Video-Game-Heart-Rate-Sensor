
window.onload = function () {
    // TODO:: Do your initialization job

    // add eventListener for tizenhwkey
    document.addEventListener('tizenhwkey', function(e) {
        if(e.keyName == "back")
	try {
	    tizen.application.getCurrentApplication().exit();
	} catch (ignore) {
	}
    });
    
 
    function onSuccess() {
    	var currentBPM = document.getElementById('bpm')
    	var socketURL = 'ws://192.168.0.13:9002';
    	var webSocket = new WebSocket(socketURL);
    	
    	
    	webSocket.onopen = function(e) {
    		console.log('connection open, readyState: ' + e.target.readyState);
   		 
    	};
    
    	webSocket.onerror = function(e) {
    		console.log('Cannot establish a connection')
    		
    	};
    	
    	
    	function onchangedCB(hrmInfo) {
    		var hrmBPM =hrmInfo.heartRate
            console.log('heart rate:' + hrmBPM);
    		
    		
    		if(hrmBPM >= 0) {
    			currentBPM.innerHTML = hrmInfo.heartRate + '  BPM'
    			 console.log('web socket: ' + webSocket.readyState);
    			 if(webSocket.readyState == 1) {
    				 webSocket.send(hrmBPM);
    				
    			 } else if(webSocket.readyState == 3) {
    				 webSocket = new WebSocket(socketURL);
    				
    			 }
    		}
           
        }
        tizen.humanactivitymonitor.start('HRM', onchangedCB);
    }

   
   function onError(e) {
	    console.log("error " + JSON.stringify(e));
	}
   
 
	tizen.ppm.requestPermission("http://tizen.org/privilege/healthinfo",onSuccess, onError);
	tizen.power.request("SCREEN", "SCREEN_NORMAL");
    
};


