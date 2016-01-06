<?php namespace App\Http\Controllers;

use Auth;
use App\Article;
use App\Http\Requests;
// for object validation
use App\Http\Requests\ArticleRequest;
use App\Http\Controllers\Controller;
use Carbon\Carbon;
// for controller validation
// use Illuminate\Http\Request;f

class ArticlesController extends Controller {

	public function __construct()
	{
		$this->middleware('auth', ['only' => 'create']);
	}
	//
	public function index()
	{
		// fetches all the articles
		// $articles = Article::latest('published_at')->get();
		// fetches all the articles where they have already been published
		// too long and messy let's make it into a scope
		$articles = Article::latest('published_at')->published()->get();
		return view('articles.index', compact('articles'));
	}

	public function show(Article $article)
	{
		// more simpler way of showing a 404
		// $article = Article::findOrFail($id);
		// another way to display a 404
		// if(is_null($article)){
		// 	abort(404);
		// }

		// dd($article->published_at);
		return view('articles.show', compact('article'));
	}

	public function create()
	{
		return view('articles.create');
	}

	/* one way controller offloads to object and proceeds if
		 everything is ok*/
	/*public function store(CreateArticleRequest $request){
		// validation occurs automatically
		// no need for facade
		Article::create($request->all());
		// one way to send form data to a new article
		// $input = Request::all();
		// Article::create($input);

		// another way is to inline it
		// Article::create(Request::all());
		return redirect('articles');
	}*/

	/* controller handles the validation */
	public function store(ArticleRequest $request)
	{
		// save article		
		// Article::create($request->all());

		// add user to article
		
		$article = new Article($request->all());
		Auth::user()->articles()->save($article);
		return redirect('articles');
	}

	public function edit(Article $article)
	{
		return view('articles.edit',compact('article'));
	}

	public function update(Article $article, ArticleRequest $request)
	{
		$article->update($request->all());
		return redirect('articles');
	}

}
