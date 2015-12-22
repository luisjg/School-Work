<?php namespace App\Http\Controllers;

use App\Http\Requests;
use App\Http\Controllers\Controller;

use Illuminate\Http\Request;

class PagesController extends Controller {

	//
	public function about(){
		// one way to pass data
		// $name = 'Herp <span style="color: red;">Derp</span>';
		// return view('pages.about')->with('name', $name);

		// second way to pass data an array
		// return view('pages.about')->with([
		// 	'first' => 'Herp',
		// 	'last' => 'Derp'
		// 	]);

		// third way second argument in the function
		// $data = [];
		// $data['first'] = 'Herp';
		// $data['last'] = 'Derp';
		// return view('pages.about', $data);

		// fourth way
		$first = 'Ander';
		// $people = [];
		$people = [
			'John', 'Joe', 'Moe', 'Manny'
		];
		return view('pages.about', compact('people'));
	}

	public function contact(){
		return view('pages.contact');
	}
}
