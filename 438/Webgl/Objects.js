var container, scene, camera, renderer, controls;
var cube;
var keyboard = new THREEx.KeyboardState();
var clock = new THREE.Clock();
/*var animOffset       = 0,   // starting frame of animation
	walking         = false,
	duration        = 1000, // milliseconds to complete animation
	keyframes       = 20,   // total number of animation frames
	interpolation   = duration / keyframes, // milliseconds per frame
	lastKeyframe    = 0,    // previous keyframe
	currentKeyframe = 0;
*/
init();
animate();
			
function init() 
{
	//Scene
	scene = new THREE.Scene();

	//Camera
	var SCREEN_WIDTH = window.innerWidth, SCREEN_HEIGHT = window.innerHeight;
	var VIEW_ANGLE = 45, ASPECT = SCREEN_WIDTH / SCREEN_HEIGHT, NEAR = 0.1, FAR = 20000;
	camera = new THREE.PerspectiveCamera( VIEW_ANGLE, ASPECT, NEAR, FAR);
	scene.add(camera);
	camera.position.set(0,150,400);
	camera.lookAt(scene.position);	
	
	
	//Renderer
	if ( Detector.webgl )
		renderer = new THREE.WebGLRenderer( {antialias:true} );
	else
		renderer = new THREE.CanvasRenderer(); 
	renderer.setSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	container = document.getElementById( 'ThreeJS' );
	container.appendChild( renderer.domElement );
	
	//Fullscreen
	THREEx.WindowResize(renderer, camera);
	THREEx.FullScreen.bindKey({ charCode : 'm'.charCodeAt(0) });
	
	//Light
	var light = new THREE.PointLight(0xffffff);
	light.position.set(0,250,0);
	scene.add(light);
	
	//Create a Cube Geometry
	var cubeGeometry = new THREE.CubeGeometry( 100, 100, 100, 1, 1, 1 );
	
	// Create Cube Mesh Array
	var cubeMaterialArray = []; //x+,x-,y+,y-,z+,z-
	cubeMaterialArray.push( new THREE.MeshBasicMaterial( { color: 0xff3333 } ) );
	cubeMaterialArray.push( new THREE.MeshBasicMaterial( { color: 0xff8800 } ) );
	cubeMaterialArray.push( new THREE.MeshBasicMaterial( { color: 0xffff33 } ) );
	cubeMaterialArray.push( new THREE.MeshBasicMaterial( { color: 0x33ff33 } ) );
	cubeMaterialArray.push( new THREE.MeshBasicMaterial( { color: 0x3333ff } ) );
	cubeMaterialArray.push( new THREE.MeshBasicMaterial( { color: 0x8833ff } ) );
	var cubeMaterials = new THREE.MeshFaceMaterial( cubeMaterialArray );

	//Create and Position Cube Object
	cube = new THREE.Mesh( cubeGeometry, cubeMaterials );
	cube.position.set(0, 0, 0);
	scene.add( cube );

	//FLOOR
	var floorTexture = new THREE.ImageUtils.loadTexture( 'http://cs.iupui.edu/~josgreer/438/Webgl/checkerboard.jpg' );
	floorTexture.wrapS = floorTexture.wrapT = THREE.RepeatWrapping; 
	floorTexture.repeat.set( 10, 10 );
	var floorMaterial = new THREE.MeshBasicMaterial( { map: floorTexture, side: THREE.DoubleSide } );
	var floorGeometry = new THREE.PlaneGeometry(1000, 1000, 10, 10);
	var floor = new THREE.Mesh(floorGeometry, floorMaterial);
	floor.position.y = -51;
	floor.rotation.x = Math.PI / 2;
	scene.add(floor);		

	

	
	//Create and Position Skybox Object
	var skyBoxGeometry = new THREE.CubeGeometry( 10000, 10000, 10000 );
	var skyBoxMaterial = new THREE.MeshBasicMaterial( { color: 0x9999ff, side: THREE.BackSide } );
	var skyBox = new THREE.Mesh( skyBoxGeometry, skyBoxMaterial );
	scene.add(skyBox);
	
	//Create Controls
	controls = new THREE.OrbitControls( camera, renderer.domElement );

}

function animate() 
{
    requestAnimationFrame( animate );
	render();
	update();
	controls.update();		
}

function update (){
	//Change in Time Since Previous Call
	delta = clock.getDelta(); 
	var moveDistance = 100 * delta;
	walking = false;
	
	// move forwards / backwards
	if ( keyboard.pressed("S") ){
		cube.translateZ( -moveDistance );
		console.log("S");
	}
	if ( keyboard.pressed("W") ){
		cube.translateZ(  moveDistance );
		console.log("W");
	}
	// rotate left/right
	if ( keyboard.pressed("A") ){
		cube.rotation.y += delta;
		console.log("A");
	}
	if ( keyboard.pressed("D") ){
		cube.rotation.y -= delta;
		console.log("D");
	}
}

function render(){	
	
	renderer.render( scene, camera );
}