<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;
use App\Http\Controllers\Controller;
use App\User;
use App\Classes;
use App\User_classes;
use DB;
use Auth;

class ClassController extends Controller
{

    public function __construct()
    {
        $this->middleware('auth');
    }

    public function index()
    {
//        select * from users
//join user_classes on user_id = users.id
//join classes on class_id = classes.id
//where users.id = 1;

        $classes = DB::table('users', 'user_classes', 'classes')
                ->select('users.*', 'classes.*', 'user_classes.*')
                ->join('user_classes', 'user_id', '=', 'users.id' )
                ->join('classes', 'class_id', '=', 'classes.id')
                ->where('users.id', Auth::id())
                ->get();

        return view('home', compact('classes'));
    }

    public function add()
    {
        return view('add');
    }

    public function store(Request $request)
    {
        Classes::create($request->all());

        return redirect('/');
    }

    public function addClass()
    {
        $users = User::all()->lists('last_name', 'id');

        $classes = Classes::all()->lists('class_code', 'id');

        return view('addClass', compact('users', 'classes'));
    }

    public function storeClass(Request $request)
    {

        $classes = new User_classes;
        $classes->user_id = $request->user_id;
        $classes->class_id = $request->class_id;
        $classes->date_taken = $request->date_taken;
        //$classes->note = $request->note;
        $classes->save();

        //flash()->success('Your Device has been added.');

        return redirect('/');
    }


}
