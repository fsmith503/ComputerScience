var confirmBox = confirm('Start swiping right?');
var like = function(){
    if (confirmBox){
      document.querySelector('[aria-label="Like"]').click();
    	};
    setTimeout(like, 100);
};
setTimeout(like, 100);
