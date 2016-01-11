<?php namespace App;

use Carbon\Carbon;
use Illuminate\Database\Eloquent\Model;

class Article extends Model {

	protected $fillable = [
			'title',
			'body',
			'published_at',
	];

	protected $dates = ['published_at'];
	// scope naming conventions
	// gets the current published articles
	public function scopePublished($query)
	{
		$query->where('published_at', '<=', Carbon::now());
	}

	// scope naming conventions
	// gets the current unpublished articles
	public function scopeUnpublished($query)
	{
		$query->where('published_at', '>', Carbon::now());
	}

	public function setPublishedAtAtrribute($date)
	{
		$this->attributes['published_at'] = Carbon::createFromForman('Y-m-d',$date);
	}

	public function user()
	{
		return $this->belongsTo('App\User');
	}

	public function tags()
	{
		return $this->belongsToMany('App\Tag')->withTimestamps();
	}

}
