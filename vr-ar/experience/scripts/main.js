function spin(){
	//model.object3D.rotation.x += rotationSpeed;
	model.object3D.rotation.y += rotationSpeed;
	//model.object3D.rotation.z += rotationSpeed/2;
	//console.log(myOtherBox.object3D.rotation);
}
setInterval(spin, 16);

var rotationSpeed = 0;
var model = document.getElementById('3dmodel');


model.addEventListener('mouseenter', function(){
	rotationSpeed = 0.05;
	console.log('entered');
});


model.addEventListener('mouseleave', function(){
	rotationSpeed = 0;
	console.log('left');
});
