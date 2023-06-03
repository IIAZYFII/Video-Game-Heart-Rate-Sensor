
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

        function onchangedCB(hrmInfo) {
    		var hrmBPM =hrmInfo.heartRate
            console.log('heart rate:' + hrmBPM);
    		
    		
    		if(hrmBPM >= 0) {
    			 currentBPM.innerHTML = hrmInfo.heartRate + '  BPM'
    		}
           
        }
        tizen.humanactivitymonitor.start('HRM', onchangedCB);
    }

   
   function onError(e) {
	    console.log("error " + JSON.stringify(e));
	}
   
 
	tizen.ppm.requestPermission("http://tizen.org/privilege/healthinfo",onSuccess, onError);
    
};
